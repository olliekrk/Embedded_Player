//
// Created by olliekrk on 21.10.2019.
//

#include <term_io.h>
#include "controls.h"
#include "audio_loader.h"
#include "audio_player.h"

AppControlsState APP_STATE = {
        -1,
        -1,
        1,
        0,
        NULL,
        0,
        NULL,
        0,
        NULL,
        NULL,
        0,
        NULL,
        0,
        AUDIO_VOLUME_INIT
};

AppButtonsState APP_BUTTONS_STATE;

void CON_Initialize_Buttons(void) {
    APP_BUTTONS_STATE.configs = malloc(NUMBER_OF_SOUND_CONTROLS * sizeof(ButtonState));
    for (int i = 0; i < NUMBER_OF_SOUND_CONTROLS; ++i) {
        APP_BUTTONS_STATE.configs[i].chosenDirectoryNumber = directoryOne;
        APP_BUTTONS_STATE.configs[i].trackName = NULL;
        APP_BUTTONS_STATE.configs[i].trackPath = NULL;
        APP_BUTTONS_STATE.configs[i].size = 0;
        APP_BUTTONS_STATE.configs[i].sampleRate = 0;
        APP_BUTTONS_STATE.configs[i].channels = 0;
    }
}

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
                CON_EnqueueAudio(button);
            } else {
                CON_ActivateOption();
            }
        default:
            return;
    }
}

void CON_HandleOptionButtonTouched(OptionControl option) {
    if (APP_STATE.SELECTED_OPTION == option) {
        APP_STATE.SELECTED_OPTION = -1;
        return;
    }
    char *dirPath = malloc(200 * sizeof(char));
    xprintf ("entering..");

    switch (option) {
        case SELECTED_TRACK:
            APP_STATE.SELECTED_OPTION = option;
            break;
        case DIRECTORY_1:
            AUDIO_L_ResetDirectory();
            APP_STATE.SELECTED_DIR_INDEX = 0;
            APP_STATE.SELECTED_DIR_NAME = APP_STATE.DIRECTORIES[APP_STATE.SELECTED_DIR_INDEX];
            sprintf(dirPath, "%s/%s", AUDIO_DIRECTORY_PATH, APP_STATE.SELECTED_DIR_NAME);
            APP_STATE.SELECTED_DIR_PATH = dirPath;
            xprintf ("Selected dir is: %s\r\n", APP_STATE.SELECTED_DIR_PATH);
            AUDIO_L_ScanDirectory();
            break;
        case DIRECTORY_2:
            AUDIO_L_ResetDirectory();
            APP_STATE.SELECTED_DIR_INDEX = 2;
            APP_STATE.SELECTED_DIR_NAME = APP_STATE.DIRECTORIES[APP_STATE.SELECTED_DIR_INDEX];
            sprintf(dirPath, "%s/%s", AUDIO_DIRECTORY_PATH, APP_STATE.SELECTED_DIR_NAME);
            APP_STATE.SELECTED_DIR_PATH = dirPath;
            xprintf ("Selected dir is: %s\r\n", APP_STATE.SELECTED_DIR_PATH);
            AUDIO_L_ScanDirectory();
            break;
        case NEXT_TRACK:
            if (APP_STATE.TRACKS_COUNT > 0 && APP_STATE.SELECTED_TRACK_INDEX + 1 < APP_STATE.TRACKS_COUNT) {
                APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[++APP_STATE.SELECTED_TRACK_INDEX];
            }
            break;
        case BACK_TRACK:
            if (APP_STATE.TRACKS_COUNT > 0 && APP_STATE.SELECTED_TRACK_INDEX - 1 >= 0) {
                APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[--APP_STATE.SELECTED_TRACK_INDEX];
            }
            break;
        default:
            xprintf("Option button touched is: %d\r\n", option);
    }
    free(dirPath);
}

void CON_ActivateOption() { //tu dorzucic opcje zmiany folderu - Nina
    if (APP_STATE.SELECTED_OPTION != -1 && APP_STATE.SELECTED_SOUND_BUTTON != -1) {

        // todo: apply selected options with selected button

        switch (APP_STATE.SELECTED_OPTION) {
            case SELECTED_TRACK:
                AUDIO_L_LoadFileUnderButton(APP_STATE.SELECTED_TRACK_NAME, APP_STATE.SELECTED_SOUND_BUTTON);
                break;
            /*case DIRECTORY_1:
                APP_BUTTONS_STATE.configs[APP_STATE.SELECTED_SOUND_BUTTON].effectEnabled = effectOne;
                break;
            case EFFECT_2:
                APP_BUTTONS_STATE.configs[APP_STATE.SELECTED_SOUND_BUTTON].effectEnabled = effectTwo;
                break;*/
            //czy tu trzeba cos zrrobic? zaladowac jeszcze raz pod guzik?
        }

        // Reset state
        APP_STATE.SELECTED_OPTION = -1;
        APP_STATE.SELECTED_SOUND_BUTTON = -1;
        APP_STATE.IS_DIRTY = 1;
    }
}

void CON_EnqueueAudio(int buttonNumber) {
    AUDIO_P_AddToQueue(buttonNumber);
}
