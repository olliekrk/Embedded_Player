//
// Created by olliekrk on 21.10.2019.
//

#include <term_io.h>
#include "controls.h"

void CON_HandleButtonTouched(int buttonNumber) {
    // todo: add non-default actions

    switch (buttonNumber) {
		case -1:
			break;
        case CON_BUTTON_0:
        case CON_BUTTON_1:
        case CON_BUTTON_2:
        case CON_BUTTON_3:
        case CON_BUTTON_4:
        case CON_BUTTON_5:
        case CON_BUTTON_6:
        case CON_BUTTON_7:
        default:
            xprintf("Button touched is: %d\r\n", buttonNumber);
    }
}