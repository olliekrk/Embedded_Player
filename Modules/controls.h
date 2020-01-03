//
// Created by olliekrk on 21.10.2019.
//

#ifndef EMBEDDED_PLAYER_CONTROLS_H
#define EMBEDDED_PLAYER_CONTROLS_H

#include <stdbool.h>

#define NUMBER_OF_SOUND_CONTROLS 8
#define NUMBER_OF_CONTROLS 13

typedef enum ChosenDirectory {
    directoryOne = 0,
    directoryTwo = 1
} ChosenDirectory;

typedef struct ButtonState {
    char *trackName;
    char *trackPath;
    uint8_t channels;
    uint16_t sampleRate; // 8k, 44.1k, etc.
    uint32_t size;
    ChosenDirectory chosenDirectoryNumber;
} ButtonState;

typedef struct AppButtonsState {
    ButtonState *configs;
} AppButtonsState;

typedef struct AppControlsState {
    int SELECTED_SOUND_BUTTON;
    int SELECTED_OPTION;
    int IS_DIRTY;
	int IS_PLAYING;

    char **DIRECTORIES;
    int DIR_COUNT;
    char *SELECTED_DIR_NAME;
    int SELECTED_DIR_INDEX;
    char *SELECTED_DIR_PATH;


    char **TRACKS;
    int TRACKS_COUNT;
    char *SELECTED_TRACK_NAME;
    int SELECTED_TRACK_INDEX;

    int VOLUME;
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
    DIRECTORY_1 = 11,
    DIRECTORY_2 = 12
} OptionControl;

extern AppControlsState APP_STATE;

extern AppButtonsState APP_BUTTONS_STATE;

void CON_Initialize_Buttons(void);

void CON_HandleButtonTouched(int);

void CON_HandleSoundButtonTouched(SoundControl);

void CON_HandleOptionButtonTouched(OptionControl); 

void CON_ActivateOption();

void CON_EnqueueAudio(int);

#endif //EMBEDDED_PLAYER_CONTROLS_H
