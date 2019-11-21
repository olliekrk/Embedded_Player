//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_CONTROLS_H
#define EMBEDDED_PLAYER_CONTROLS_H

//#include <semphr.h>

#define NUMBER_OF_SOUND_CONTROLS 8
#define NUMBER_OF_CONTROLS 13

typedef struct AppControlsState {
    int SELECTED_SOUND_BUTTON;
    int SELECTED_OPTION;
    int IS_TOUCHED;

    char **TRACKS;
    int TRACKS_COUNT;
    char *SELECTED_TRACK_NAME;
    int SELECTED_TRACK_INDEX;
} AppControlsState;

typedef enum SoundControl {
    CON_BUTTON_0 = 0,
    CON_BUTTON_1 = 1,
    CON_BUTTON_2 = 2,
    CON_BUTTON_3 = 3,
    CON_BUTTON_4 = 4,
    CON_BUTTON_5 = 5,
    CON_BUTTON_6 = 6,
    CON_BUTTON_7 = 7,
} SoundControl;

typedef enum OptionControl {
    NEXT_TRACK = 8,
    BACK_TRACK = 9,
    SELECTED_TRACK = 10,
    EFFECT_1 = 11,
    EFFECT_2 = 12
} OptionControl;

extern AppControlsState APP_STATE;

//extern SemaphoreHandle_t AppStateMutex;

void CON_HandleButtonTouched(int);

void CON_HandleSoundButtonTouched(SoundControl);

void CON_HandleOptionButtonTouched(OptionControl);

void CON_ActivateOption();

void CON_PlayLoadedSound(int);

#endif //EMBEDDED_PLAYER_CONTROLS_H
