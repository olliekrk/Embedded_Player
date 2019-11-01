//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_GUI_H
#define EMBEDDED_PLAYER_GUI_H

#include <ts.h>

#define GUI_buttons_in_row 4
#define GUI_button_rows 2
#define GUI_margin 4

#define GUI_touch_radius 4
#define GUI_max_touches 6

uint32_t GUI_GetXButtonSize(void);

uint32_t GUI_GetYButtonSize(void);

void GUI_DrawButton(uint32_t, uint32_t, int, int, int, int, char *);

void GUI_DrawAllButtons(void);

void GUI_HandleTouch(TS_StateTypeDef *, void (*handleButtonTouch)(int));

void GUI_HighlightSoundButton(int);

int GUI_GetButtonNumber(int, int);

int GUI_IsSoundButtonTouched(int);

#endif //EMBEDDED_PLAYER_GUI_H
