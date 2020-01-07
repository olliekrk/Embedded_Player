//
// Created by olliekrk on 21.10.2019.
//

#include <stm32746g_discovery_ts.h>
#include "stm32746g_discovery_lcd.h"
#include "gui.h"
#include "gui_colors.h"
#include "controls.h"
#include <string.h>
#include <stdlib.h>

uint32_t GUI_GetXButtonSize() {
    return (BSP_LCD_GetXSize() - 2 * GUI_margin) / GUI_buttons_in_row;
}

uint32_t GUI_GetYButtonSize() {
    return (BSP_LCD_GetYSize() - 2 * GUI_margin) / (GUI_sound_rows + 1); // 1/N of screen is for player information
}

int GUI_GetButtonForCoords(int x, int y) {
    uint8_t column = (x - GUI_margin) / GUI_GetXButtonSize();
    uint8_t row = (y - GUI_margin) / GUI_GetYButtonSize();

    if (column >= 0 && column < GUI_buttons_in_row && row >= 0 && row < GUI_sound_rows) {
        return (SoundControl) (column + row * GUI_buttons_in_row);
    } else {
        int rowUpperSection = y <= GUI_margin + 2.5 * GUI_GetYButtonSize();

        if (column == 0) {
            return rowUpperSection ? NEXT_TRACK : BACK_TRACK;
        } else if (column == 3) {
            return rowUpperSection ? NEXT_DIRECTORY : BACK_DIRECTORY;
        } else if (rowUpperSection) {
            return SELECTED_TRACK;
        } else {
            return column == 1 ? VOLUME_UP : VOLUME_DOWN;
        }
    }
}

int GUI_GetCoordsForButton(int buttonNumber, int *xOutput, int *yOutput) {
    if (buttonNumber < 0 || buttonNumber >= NUMBER_OF_CONTROLS) {
        return -1;
    }

    if (buttonNumber < NUMBER_OF_SOUND_CONTROLS) {
        *xOutput = GUI_margin + (buttonNumber % GUI_buttons_in_row) * GUI_GetXButtonSize();
        *yOutput = GUI_margin + (buttonNumber / GUI_buttons_in_row) * GUI_GetYButtonSize();
    } else if (buttonNumber == NEXT_TRACK || buttonNumber == BACK_TRACK) {
        *xOutput = GUI_margin;
        *yOutput = GUI_margin + (buttonNumber == NEXT_TRACK ? 2 : 2.5) * GUI_GetYButtonSize();
    } else if (buttonNumber == SELECTED_TRACK) {
        *xOutput = GUI_margin + GUI_GetXButtonSize();
        *yOutput = GUI_margin + 2 * GUI_GetYButtonSize();
    } else if (buttonNumber == VOLUME_UP || buttonNumber == VOLUME_DOWN) {
        *xOutput = GUI_margin + (buttonNumber == VOLUME_UP ? 1 : 2) * GUI_GetXButtonSize();
        *yOutput = GUI_margin + (int) (2.5 * GUI_GetYButtonSize());
    } else {
        *xOutput = GUI_margin + 3 * GUI_GetXButtonSize();
        *yOutput = GUI_margin + (buttonNumber == NEXT_DIRECTORY ? 2 : 2.5) * GUI_GetYButtonSize();
    }

    return 0;
}

void GUI_GetSizeForButton(int buttonNumber, int *xSizeOutput, int *ySizeOutput) {
    if (buttonNumber >= 0 && buttonNumber < NUMBER_OF_SOUND_CONTROLS) {
        *xSizeOutput = GUI_GetXButtonSize();
        *ySizeOutput = GUI_GetYButtonSize();
    } else if (buttonNumber == SELECTED_TRACK) {
        *xSizeOutput = (int) (2 * GUI_GetXButtonSize());
        *ySizeOutput = (int) (0.5 * GUI_GetYButtonSize());
    } else {
        *xSizeOutput = GUI_GetXButtonSize();
        *ySizeOutput = (int) (0.5 * GUI_GetYButtonSize());
    }
}

void GUI_GetColorsForButton(int buttonNumber, uint32_t *primaryOutput, uint32_t *accentOutput) {
    switch (buttonNumber) {
        case NEXT_TRACK:
        case BACK_TRACK:
        case NEXT_DIRECTORY:
        case BACK_DIRECTORY:
            *primaryOutput = COLOR_PRIMARY_OPTION;
            *accentOutput = COLOR_ACCENT_OPTION;
            break;
        case SELECTED_TRACK:
            *primaryOutput = COLOR_PRIMARY_SELECTED;
            *accentOutput = COLOR_ACCENT_SELECTED;
            break;
        case VOLUME_UP:
        case VOLUME_DOWN:
            *primaryOutput = COLOR_SECONDARY_OPTION;
            *accentOutput = COLOR_ACCENT_OPTION;
            break;
        default:
            // sound button case
            *primaryOutput = APP_BUTTONS_STATE.configs[buttonNumber].size > 0 ? COLOR_PRIMARY_DEFAULT
                                                                              : COLOR_PRIMARY_DEFAULT_DARK;
            *accentOutput = COLOR_ACCENT_DEFAULT;
    }
}

const char *GUI_GetTextForButton(int buttonNumber) {
    char *text;

    switch (buttonNumber) {
        case SELECTED_TRACK:
            text = APP_STATE.SELECTED_TRACK_NAME;
            if (text == NULL) return "Please wait.";
            break;
        case NEXT_DIRECTORY:
            text = APP_STATE.SELECTED_DIR_NAME;
            if (text == NULL) return "- Empty -";
            break;
        case BACK_DIRECTORY:
            text = (APP_STATE.SELECTED_DIR_INDEX - 1) >= 0 ?
                   APP_STATE.DIRECTORIES[APP_STATE.SELECTED_DIR_INDEX - 1] : NULL;
            if (text == NULL) return "- Empty -";
            break;
        case VOLUME_UP:
            return "Too quiet?";
        case VOLUME_DOWN:
            return "Too loud?";
        case NEXT_TRACK:
            return "Next";
        case BACK_TRACK:
            return "Previous";
        default:
            text = APP_BUTTONS_STATE.configs[buttonNumber].trackName;
            if (text == NULL) return "-";
            break;
    }

    return text;
}

void GUI_DrawTextAtCenter(uint32_t backgroundColor, int x, int y, char *text) {
    BSP_LCD_SetTextColor(COLOR_TEXT);
    BSP_LCD_SetBackColor(backgroundColor);
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(x + GUI_margin, y + GUI_margin, (uint8_t *) text, LEFT_MODE);
}

void GUI_DrawButton(uint32_t buttonColor, uint32_t frameColor, int x, int y, int xSize, int ySize, const char *text) {
    BSP_LCD_SetTextColor(buttonColor);
    BSP_LCD_FillRect(x, y, xSize, ySize);
    BSP_LCD_SetTextColor(frameColor);
    BSP_LCD_DrawRect(x, y, xSize, ySize);

    // trim too long text
    char *textDisplayed = malloc(TEXT_DISPLAYED_MAXLENGTH * sizeof(char));
    strlen(text) > TEXT_DISPLAYED_MAXLENGTH ?
    sprintf(textDisplayed, "%.*s...", TEXT_DISPLAYED_MAXLENGTH - 3, text) :
    sprintf(textDisplayed, "%s", text);
    GUI_DrawTextAtCenter(buttonColor, x, y, textDisplayed);
    free(textDisplayed);
}

void GUI_DrawAllButtons() {
    int x, y, xSize, ySize;
    uint32_t primaryColor, accentColor;

    for (int i = 0; i < NUMBER_OF_CONTROLS; i++) {
        GUI_GetCoordsForButton(i, &x, &y);
        GUI_GetSizeForButton(i, &xSize, &ySize);
        GUI_GetColorsForButton(i, &primaryColor, &accentColor);
        GUI_DrawButton(primaryColor, accentColor, x, y, xSize, ySize, GUI_GetTextForButton(i));
    }
}

void GUI_HighlightButton(int buttonNumber) {
    int x, y, xSize, ySize;
    uint32_t primaryColor, accentColor;
    GUI_GetCoordsForButton(buttonNumber, &x, &y);
    GUI_GetSizeForButton(buttonNumber, &xSize, &ySize);
    GUI_GetColorsForButton(buttonNumber, &primaryColor, &accentColor);
    GUI_DrawButton(primaryColor, COLOR_HIGHLIGHTED, x, y, xSize, ySize, GUI_GetTextForButton(buttonNumber));
}

void GUI_HandleTouch(TS_StateTypeDef *tsState, void (*handleButtonTouch)(int)) {
    int touchesDetected = tsState->touchDetected;
    int touchesToHandle = touchesDetected > GUI_max_touches ? GUI_max_touches : touchesDetected;
    int x;
    int y;

    BSP_LCD_SetTextColor(COLOR_PRIMARY_SELECTED);
    for (int i = 0; i < touchesToHandle; i++) {
        x = tsState->touchX[i];
        y = tsState->touchY[i];
        (*handleButtonTouch)(GUI_GetButtonForCoords(x, y)); // callback function
    }
}

void GUI_DrawIconOnButtonCentered(int buttonNumber) {
    int xButton, yButton, xButtonSize, yButtonSize;
    uint32_t primaryColor, accentColor;
    GUI_GetCoordsForButton(buttonNumber, &xButton, &yButton);
    GUI_GetSizeForButton(buttonNumber, &xButtonSize, &yButtonSize);
    GUI_GetColorsForButton(buttonNumber, &primaryColor, &accentColor);

    BSP_LCD_SetTextColor(accentColor);
    double circleRadius = 0.1 * (xButtonSize < yButtonSize ? xButtonSize : yButtonSize);
    BSP_LCD_FillCircle(xButton + 0.5 * xButtonSize, yButton + 0.5 * yButtonSize, circleRadius);
}

pPoint getArrowUpForCoordsAndSize(int xCenter, int yCenter, int aSize) {
    pPoint points = malloc(3 * sizeof(Point));
    points[0].X = xCenter;
    points[1].X = xCenter - (0.5 * aSize);
    points[2].X = xCenter + (0.5 * aSize);
    points[0].Y = yCenter - (0.5 * aSize);
    points[1].Y = yCenter + (0.5 * aSize);
    points[2].Y = yCenter + (0.5 * aSize);
    return points;
}

pPoint getArrowDownForCoordsAndSize(int xCenter, int yCenter, int aSize) {
    pPoint points = getArrowUpForCoordsAndSize(xCenter, yCenter, aSize);
    points[0].Y += aSize;
    points[1].Y -= aSize;
    points[2].Y -= aSize;
    return points;
}

void GUI_DrawAllIcons() {
    GUI_DrawIconOnButtonCentered(VOLUME_UP);
    GUI_DrawIconOnButtonCentered(VOLUME_DOWN);
//    pPoint points = getArrowDownForCoordsAndSize(100, 100, 20);
//    BSP_LCD_FillPolygon(points, 3);
//    free(points);
}