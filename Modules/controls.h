//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_CONTROLS_H
#define EMBEDDED_PLAYER_CONTROLS_H

enum MainControls {
    CON_BUTTON_0 = 0,
    CON_BUTTON_1 = 1,
    CON_BUTTON_2 = 2,
    CON_BUTTON_3 = 3,
    CON_BUTTON_4 = 4,
    CON_BUTTON_5 = 5,
    CON_BUTTON_6 = 6,
    CON_BUTTON_7 = 7,
};

void CON_HandleButtonTouched(int);

#endif //EMBEDDED_PLAYER_CONTROLS_H
