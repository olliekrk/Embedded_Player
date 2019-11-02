//
// Created by olliekrk on 21.10.2019.
//

#include <stm32746g_discovery_ts.h>
#include <term_io.h>
#include "gui.h"
#include "stm32746g_discovery_lcd.h"

uint32_t GUI_GetXButtonSize() {
    return (BSP_LCD_GetXSize() - GUI_margin) / GUI_buttons_in_row;
}

uint32_t GUI_GetYButtonSize() {
    return (BSP_LCD_GetYSize() - GUI_margin) / (GUI_button_rows + 1); // 1/N of screen is for player information
}

void GUI_DrawButtons(void) {
    BSP_LCD_Clear(LCD_COLOR_LIGHTGRAY);

    int xSize = GUI_GetXButtonSize();
    int ySize = GUI_GetYButtonSize();

    for (int row = 0; row < GUI_button_rows; row++) {
        for (int col = 0; col < GUI_buttons_in_row; col++) {
            int x = GUI_margin + col * xSize;
            int y = GUI_margin + row * ySize;

            BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
            BSP_LCD_FillRect(x, y, xSize, ySize);

            BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
            BSP_LCD_DrawRect(x, y, xSize, ySize);
        }
    }
}

void GUI_HandleTouch(TS_StateTypeDef *tsState, void (*handleButtonTouch)(int)) {
    int touchesDetected = tsState->touchDetected;
    int touchesToHandle = touchesDetected > GUI_max_touches ? GUI_max_touches : touchesDetected;
    int x;
    int y;
	
    BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGREEN);
    for (int i = 0; i < touchesToHandle; i++) {
        x = tsState->touchX[i];
        y = tsState->touchY[i];
        BSP_LCD_FillCircle(x, y, GUI_touch_radius);
        (*handleButtonTouch)(GUI_GetButtonNumber(x, y)); // callback function
    }
}

int GUI_GetButtonNumber(int x, int y) {
    // todo: verify this

    uint32_t xNumber = (x - GUI_margin) / GUI_GetXButtonSize();
    uint32_t yNumber = (y - GUI_margin) / GUI_GetYButtonSize();

    if (xNumber < 0 || yNumber < 0 || xNumber >= GUI_buttons_in_row || yNumber >= GUI_button_rows) return -1;

    return (int) (xNumber + yNumber * GUI_buttons_in_row);
}
