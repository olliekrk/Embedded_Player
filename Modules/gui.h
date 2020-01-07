//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_GUI_H
#define EMBEDDED_PLAYER_GUI_H

#include "stm32746g_discovery_ts.h"

#define GUI_buttons_in_row 4
#define GUI_sound_rows 2
#define GUI_margin 4
#define GUI_max_touches 6

#define TEXT_DISPLAYED_MAXLENGTH 15

// UTIL
uint32_t GUI_GetXButtonSize(void);

uint32_t GUI_GetYButtonSize(void);

int GUI_GetButtonForCoords(int, int);

int GUI_GetCoordsForButton(int, int *, int *);

void GUI_GetSizeForButton(int, int *, int *);

void GUI_GetColorsForButton(int, uint32_t *, uint32_t *);

const char *GUI_GetTextForButton(int);

// DISPLAY
void GUI_DrawTextAtCenter(uint32_t, int, int, char *);

void GUI_DrawButton(uint32_t, uint32_t, int, int, int, int, const char *);

void GUI_DrawAllButtons(void);

void GUI_DrawIconOnButtonCentered(int);

void GUI_DrawAllIcons(void);

void GUI_HighlightButton(int);

// HANDLER
void GUI_HandleTouch(TS_StateTypeDef *, void (*handleButtonTouch)(int));

#endif //EMBEDDED_PLAYER_GUI_H
