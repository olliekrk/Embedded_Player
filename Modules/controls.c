//
// Created by olliekrk on 21.10.2019.
//

#include <term_io.h>
#include "controls.h"

AppControlsState APP_STATE = {
        -1,
        -1,
        1,
        NULL,
        0,
        NULL,
        0
};

SemaphoreHandle_t AppStateMutex;

void CON_HandleButtonTouched(int buttonNumber) {
    if (buttonNumber < 0 || buttonNumber >= NUMBER_OF_CONTROLS)
        return;

    if (buttonNumber < NUMBER_OF_SOUND_CONTROLS) {
        CON_HandleSoundButtonTouched(buttonNumber);
    } else {
        CON_HandleOptionButtonTouched(buttonNumber);
    }
}

void CON_HandleSoundButtonTouched(SoundControl button) {
    switch (button) {
        case CON_BUTTON_0:
        case CON_BUTTON_1:
        case CON_BUTTON_2:
        case CON_BUTTON_3:
        case CON_BUTTON_4:
        case CON_BUTTON_5:
        case CON_BUTTON_6:
        case CON_BUTTON_7:
            APP_STATE.SELECTED_SOUND_BUTTON = button;
            if (APP_STATE.SELECTED_OPTION == -1) {
                CON_PlayLoadedSound(button);
            } else {
                CON_ActivateOption();
            }
        default:
            xprintf("Sound button touched is: %d\r\n", button);
    }
}

void CON_HandleOptionButtonTouched(OptionControl option) {
    switch (option) {
        case SELECTED_TRACK:
        case EFFECT_1:
        case EFFECT_2:
            APP_STATE.SELECTED_OPTION = option;
            break;
        case NEXT_TRACK:
            if (APP_STATE.TRACKS_COUNT > 0 && APP_STATE.SELECTED_TRACK_INDEX + 1 < APP_STATE.TRACKS_COUNT) {
                APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[++APP_STATE.SELECTED_TRACK_INDEX];
            }
            break;
        case BACK_TRACK:
            if (APP_STATE.TRACKS_COUNT > 0 && APP_STATE.SELECTED_TRACK_INDEX - 1 > 0) {
                APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[--APP_STATE.SELECTED_TRACK_INDEX];
            }
            break;
        default:
            xprintf("Option button touched is: %d\r\n", option);
    }
}

void CON_ActivateOption() {
    if (APP_STATE.SELECTED_OPTION && APP_STATE.SELECTED_SOUND_BUTTON) {
        switch (APP_STATE.SELECTED_OPTION) {
            // todo: apply selected option to selected button
            default:
                xprintf("Option no. %d activated with button: %d. \r\n",
                        APP_STATE.SELECTED_OPTION,
                        APP_STATE.SELECTED_SOUND_BUTTON
                );
        }

        // Reset state
        APP_STATE.SELECTED_OPTION = -1;
        APP_STATE.SELECTED_SOUND_BUTTON = -1;
    }
}

void CON_PlayLoadedSound(int buttonNumber) {
    // todo: implement + this should be called in separate 'player' thread (sounds queue?)
}
