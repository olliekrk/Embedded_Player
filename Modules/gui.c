//
// Created by olliekrk on 21.10.2019.
//

#include <stm32746g_discovery_ts.h>
#include "stm32746g_discovery_lcd.h"
#include "gui.h"
#include "gui_colors.h"
#include "controls.h"

uint32_t GUI_GetXButtonSize() {
    return (BSP_LCD_GetXSize() - GUI_margin) / GUI_buttons_in_row;
}

uint32_t GUI_GetYButtonSize() {
    return (BSP_LCD_GetYSize() - GUI_margin) / (GUI_button_rows + 1); // 1/N of screen is for player information
}

void GUI_DrawTextAtCenter(int x, int y, int ySize, char *text) {
    BSP_LCD_SetFont(&Font12);
    BSP_LCD_DisplayStringAt(x + GUI_margin * 2, y + ySize + GUI_margin, (uint8_t *) text, CENTER_MODE);
}

void GUI_DrawButton(uint32_t backgroundColor, uint32_t frameColor, int x, int y, int xSize, int ySize, char *text) {
    BSP_LCD_SetTextColor(backgroundColor);
    BSP_LCD_FillRect(x, y, xSize, ySize);

    BSP_LCD_SetTextColor(frameColor);
    BSP_LCD_DrawRect(x, y, xSize, ySize);

    GUI_DrawTextAtCenter(x, y, ySize, text);
}

void GUI_DrawAllButtons(void) {
    uint32_t bigButtonXSize = GUI_GetXButtonSize();
    uint32_t bigButtonYSize = GUI_GetYButtonSize();
    uint32_t smallButtonYSize = GUI_GetYButtonSize() / 2;

    BSP_LCD_Clear(COLOR_DEFAULT);

    // Sound buttons
    for (int row = 0; row < GUI_button_rows; row++) {
        for (int col = 0; col < GUI_buttons_in_row; col++) {
            int x = GUI_margin + col * bigButtonXSize;
            int y = GUI_margin + row * bigButtonYSize;
            GUI_DrawButton(COLOR_PRIMARY_DEFAULT, COLOR_ACCENT_DEFAULT, x, y, bigButtonXSize, bigButtonYSize, "");
        }
    }

    // Switch track to be loaded buttons
    uint32_t trackButtonY = GUI_margin + GUI_button_rows * bigButtonYSize;
    GUI_DrawButton(
            COLOR_PRIMARY_OPTION, COLOR_ACCENT_OPTION,
            GUI_margin, trackButtonY,
            bigButtonXSize, smallButtonYSize,
            "NEXT"
    );
    GUI_DrawButton(
            COLOR_PRIMARY_OPTION, COLOR_ACCENT_OPTION,
            GUI_margin, trackButtonY + smallButtonYSize,
            bigButtonXSize, smallButtonYSize,
            "BACK"
    );

    // Effects buttons
    uint32_t effectButtonX = GUI_margin + (GUI_buttons_in_row - 1) * bigButtonXSize;
    uint32_t effectButtonY = GUI_margin + GUI_button_rows * bigButtonYSize;
    GUI_DrawButton(
            COLOR_PRIMARY_OPTION, COLOR_ACCENT_OPTION,
            effectButtonX, effectButtonY,
            bigButtonXSize, smallButtonYSize,
            "E1"
    );
    GUI_DrawButton(
            COLOR_PRIMARY_OPTION, COLOR_ACCENT_OPTION,
            effectButtonX, effectButtonY + smallButtonYSize,
            bigButtonXSize, smallButtonYSize,
            "E2"
    );
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
        BSP_LCD_FillCircle(x, y, GUI_touch_radius);
        if (GUI_IsSoundButtonTouched(y)) {
            (*handleButtonTouch)(GUI_GetButtonNumber(x, y)); // callback function
        } else {
            CON_HandleOptionsTouch(x, y);
        }
    }
}

void GUI_HighlightSoundButton(int buttonNumber) {
    int xSize = GUI_GetXButtonSize();
    int ySize = GUI_GetYButtonSize();

    int x = GUI_margin + (buttonNumber % GUI_buttons_in_row) * xSize;
    int y = GUI_margin + (buttonNumber / GUI_buttons_in_row) * ySize;

    GUI_DrawButton(
            COLOR_PRIMARY_DEFAULT, COLOR_ACCENT_SELECTED,
            x, y,
            xSize, ySize,
            "SELECTED"
    );
}

int GUI_GetButtonNumber(int x, int y) {
    uint32_t xNumber = (x - GUI_margin) / GUI_GetXButtonSize();
    uint32_t yNumber = (y - GUI_margin) / GUI_GetYButtonSize();

    if (xNumber < 0 || yNumber < 0 || xNumber >= GUI_buttons_in_row || yNumber >= GUI_button_rows) return -1;

    return (int) (xNumber + yNumber * GUI_buttons_in_row);
}

int GUI_IsSoundButtonTouched(int y) {
    return y < GUI_margin + GUI_button_rows * GUI_GetYButtonSize();
}
