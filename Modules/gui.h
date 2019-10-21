//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_GUI_H
#define EMBEDDED_PLAYER_GUI_H

#include <ts.h>

#define GUI_buttons_in_row 4
#define GUI_button_rows 2
#define GUI_margin 4

#define GUI_touch_radius 10
#define GUI_max_touches 6

uint32_t GUI_GetXButtonSize(void);
uint32_t GUI_GetYButtonSize(void);

void GUI_DrawButtons(void);
void GUI_DrawTouch(TS_StateTypeDef*);

#endif //EMBEDDED_PLAYER_GUI_H
