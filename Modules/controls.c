//
// Created by olliekrk on 21.10.2019.
//

#include <term_io.h>
#include "controls.h"
#include "gui.h"

void CON_HandleButtonTouched(int buttonNumber) {
    switch (buttonNumber) {
        case CON_BUTTON_0:
        case CON_BUTTON_1:
        case CON_BUTTON_2:
        case CON_BUTTON_3:
        case CON_BUTTON_4:
        case CON_BUTTON_5:
        case CON_BUTTON_6:
        case CON_BUTTON_7:
            CON_PlayLoadedSound(buttonNumber);

            if (SELECTED_BUTTON != buttonNumber) {
                SELECTED_BUTTON = buttonNumber;
                GUI_HighlightSoundButton(SELECTED_BUTTON);
            } else {
                SELECTED_BUTTON = -1;
                GUI_DrawAllButtons();
            }
        default:
            xprintf("Button touched is: %d\r\n", buttonNumber);
    }
}

void CON_PlayLoadedSound(int buttonNumber) {

}