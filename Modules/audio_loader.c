//
// Created by olliekrk on 24.10.2019.
//

#include <ff.h>
#include <term_io.h>
#include <stm32746g_discovery_audio.h>
#include "audio_loader.h"
#include "controls.h"
#include "gui.h"
#include "audio_player.h"

int FILE_OFFSET = 0;
BufferPos BUFFER_OFFSET = BUFFER_OFFSET_NONE;
FIL CURRENT_FILE;

uint8_t AUDIO_BUFFER[AUDIO_BUFFER_SIZE] __attribute__((section(".sdram")));
uint8_t PLAYER_BUFFER[PLAYER_BUFFER_SIZE] __attribute__((section(".sdram")));

FRESULT AUDIO_L_CreateAudioDirectory(void) {
#if _FS_READONLY
    xprintf("\r\n(!) Cannot create audio directory as read-only configuration is used. (!)\r\n");
    return FR_DENIED;
#else
    FRESULT result = f_mkdir(AUDIO_DIRECTORY_PATH);
    if (result == FR_EXIST) {
        xprintf("Audio directory already exists.\r\n");
    }
    return result;
#endif
}

void AUDIO_L_SearchForDirectories() {
    DIR audioDirectory;
    FRESULT result;
    FILINFO fileInfo;

    result = f_opendir(&audioDirectory, AUDIO_DIRECTORY_PATH);
    if (result == FR_OK) {
        int dir_count = 0;
        result = f_readdir(&audioDirectory, &fileInfo);
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && dir_count < AUDIO_DIRECTORIES_LIMIT) {
            if (fileInfo.fattrib & AM_DIR) {
                xprintf("Found (%d) directory: '%s'\r\n", ++dir_count, fileInfo.fname);
                APP_STATE.DIRECTORIES[APP_STATE.DIR_COUNT] = malloc((strlen(fileInfo.fname) + 1) * sizeof(char));
                strcpy(APP_STATE.DIRECTORIES[APP_STATE.DIR_COUNT], fileInfo.fname);
                APP_STATE.DIR_COUNT++;
            }
            result = f_readdir(&audioDirectory, &fileInfo);
        }
        f_closedir(&audioDirectory);

        // Set default selected directory
        APP_STATE.SELECTED_DIR_INDEX = 0;
        APP_STATE.SELECTED_DIR_NAME = APP_STATE.DIRECTORIES[APP_STATE.SELECTED_DIR_INDEX];
        APP_STATE.IS_DIRTY = 1;
    } else if (result == FR_NO_FILE || result == FR_NO_PATH) {
        xprintf("Empty audio directory will be created.\r\n");
        if (AUDIO_L_CreateAudioDirectory() != FR_OK) {
            xprintf("Creation of audio directory has failed. Check if read-only mode of FatFs is off.\r\n");
        }
    } else {
        xprintf("Directories scan has failed with code %d\r\n.", result);
    }
}

void AUDIO_L_SearchForTracksInCurrentDir() {
    DIR directory;
    FRESULT result;
    FILINFO fileInfo;

    char *dirPath = malloc(100 * sizeof(char));
    sprintf(dirPath, "%s/%s", AUDIO_DIRECTORY_PATH, APP_STATE.SELECTED_DIR_NAME);
    result = f_opendir(&directory, dirPath);

    xprintf("Searching in dir: %s\r\n", dirPath);
    if (result == FR_OK) {
        int count = 0;
        result = f_findfirst(&directory, &fileInfo, dirPath, "*.wav");
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && count < AUDIO_FILES_LIMIT) {
            xprintf("Found (%d) wav file: %s\r\n", ++count, fileInfo.fname);
            APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT] = malloc((strlen(fileInfo.fname) + 1) * sizeof(char));
            strcpy(APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT], fileInfo.fname);
            APP_STATE.TRACKS_COUNT++;
            result = f_findnext(&directory, &fileInfo);
        }
        f_closedir(&directory);

        // Set default selected track
        APP_STATE.SELECTED_TRACK_INDEX = 0;
        APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[0];
        APP_STATE.IS_DIRTY = 1;
    } else if (result == FR_NO_PATH)
        xprintf("There is no such directory.\r\n");
    else if (result == FR_NO_FILE)
        xprintf("Found zero WAV files in this directory.");
    else
        xprintf("Directory '%s' scan has failed with code %d.\r\n", APP_STATE.SELECTED_DIR_NAME, result);

    free(dirPath);
}

void AUDIO_L_ChangeDirectory(int dirIndex) {
    APP_STATE.LOADER_BUSY = 1;
    AUDIO_L_ResetTracksData();
    APP_STATE.SELECTED_DIR_INDEX = dirIndex;
    APP_STATE.SELECTED_DIR_NAME = APP_STATE.DIRECTORIES[dirIndex];
    AUDIO_L_SearchForTracksInCurrentDir();
    APP_STATE.LOADER_BUSY = 0;
}

void AUDIO_L_InitialScan(void) {
    AUDIO_L_CreateAudioDirectory();
    AUDIO_L_ResetAll();
    AUDIO_L_SearchForDirectories();
    APP_STATE.IS_DIRTY = 1;
    AUDIO_L_SearchForTracksInCurrentDir();
    APP_STATE.IS_DIRTY = 1; // to display recently loaded tracks
}

void AUDIO_L_ResetAll(void) {
    AUDIO_L_ResetTracksData();
    AUDIO_L_ResetDirectoriesData();
    AUDIO_L_ResetPlayerState();
}

void AUDIO_L_ResetTracksData(void) {
    for (int i = 0; i < APP_STATE.TRACKS_COUNT; i++) free(APP_STATE.TRACKS[i]);
    free(APP_STATE.TRACKS);
    APP_STATE.TRACKS = malloc(AUDIO_FILES_LIMIT * sizeof(char *));
    APP_STATE.TRACKS_COUNT = 0;
    APP_STATE.SELECTED_TRACK_INDEX = 0;
    APP_STATE.SELECTED_TRACK_NAME = "";
    APP_STATE.IS_DIRTY = 1; // to refresh view
}

void AUDIO_L_ResetDirectoriesData(void) {
    for (int i = 0; i < APP_STATE.DIR_COUNT; i++) free(APP_STATE.DIRECTORIES[i]);
    free(APP_STATE.DIRECTORIES);
    APP_STATE.DIRECTORIES = malloc(AUDIO_DIRECTORIES_LIMIT * sizeof(char *));
    APP_STATE.DIR_COUNT = 0;
    APP_STATE.SELECTED_DIR_INDEX = 0;
    APP_STATE.SELECTED_DIR_NAME = "";
    APP_STATE.LOADER_BUSY = 0;
    APP_STATE.IS_DIRTY = 1; // to refresh view
}

void AUDIO_L_ResetPlayerState() {
    AUDIO_P_End();
    APP_STATE.VOLUME = AUDIO_VOLUME_INIT;
}

void AUDIO_L_ToggleContinuousMode() {
    AUDIO_L_ResetPlayerState();
    PLAYER_STATE.continuousModeOn = !PLAYER_STATE.continuousModeOn;
}

void AUDIO_L_LoadFileUnderButton(char *fileName, int buttonNumber) {
    FIL file;
    FRESULT result;
    UINT _bytesRead;

    char *filePath = malloc(200 * sizeof(char));
    if (sprintf(filePath, "%s/%s/%s", AUDIO_DIRECTORY_PATH, APP_STATE.SELECTED_DIR_NAME, fileName) > 0) {
        result = f_open(&file, filePath, FA_READ);
        if (result == FR_OK) {
            ButtonState *state = &APP_BUTTONS_STATE.configs[buttonNumber];
            state->size = f_size(&file);

            int initOffset = buttonNumber * BUFFER_LIMIT_PER_BUTTON;

            // retrieve essential info about file
            f_lseek(&file, 22);
            f_read(&file, &AUDIO_BUFFER[initOffset], 4, &_bytesRead);
            state->channels = AUDIO_BUFFER[initOffset];
            state->sampleRate = (AUDIO_BUFFER[initOffset + 3] << 8) + AUDIO_BUFFER[2];

            // skip WAV header & load onto buffer
            f_lseek(&file, WAV_HEADER_LENGTH);
            f_read(&file,
                   &AUDIO_BUFFER[buttonNumber * BUFFER_LIMIT_PER_BUTTON],
                   BUFFER_LIMIT_PER_BUTTON,
                   &_bytesRead
            );
            f_close(&file);

            // free previously allocated memory and update app buttons state
            free(state->trackPath);
            free(state->trackName);
            state->trackPath = filePath;
            state->trackName = malloc(TEXT_DISPLAYED_MAXLENGTH * sizeof(char));
            sprintf(state->trackName, "%s", fileName);
            xprintf("Successfully read audio file: %s.\r\n", filePath);
        } else {
            xprintf("An error has occurred when loading file onto buffer: %d.\r\n", result);
        }
    }
}

void AUDIO_L_StartPlayingFromButton(int buttonNumber) {
    ButtonState buttonState = APP_BUTTONS_STATE.configs[buttonNumber];
    AUDIO_L_StartPlayingFromFile(buttonState.trackPath);
}

void AUDIO_L_StartPlayingFromFile(const char *filePath) {
    int bytesRead;

    if (f_open(&CURRENT_FILE, filePath, FA_READ) == FR_OK) {
        f_lseek(&CURRENT_FILE, WAV_HEADER_LENGTH); // skip the header
        f_read(&CURRENT_FILE, &PLAYER_BUFFER[0], PLAYER_BUFFER_SIZE, (void *) &bytesRead);

        FILE_OFFSET = WAV_HEADER_LENGTH + bytesRead;
        BUFFER_OFFSET = BUFFER_OFFSET_NONE;
    }
}

void AUDIO_L_UpdatePlayerBuffer() {
    uint32_t bytesRead;
    FRESULT result;

    switch (BUFFER_OFFSET) {
        case BUFFER_OFFSET_HALF:
            BUFFER_OFFSET = BUFFER_OFFSET_NONE;
            result = f_read(&CURRENT_FILE,
                            &PLAYER_BUFFER[0],
                            PLAYER_BUFFER_SIZE / 2,
                            (void *) &bytesRead);
            break;
        case BUFFER_OFFSET_FULL:
            BUFFER_OFFSET = BUFFER_OFFSET_NONE;
            result = f_read(&CURRENT_FILE,
                            &PLAYER_BUFFER[PLAYER_BUFFER_SIZE / 2],
                            PLAYER_BUFFER_SIZE / 2,
                            (void *) &bytesRead);
            break;
        default:
            return;
    }

    if (result == FR_OK) {
        FILE_OFFSET += bytesRead;
    } else {
        BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
        AUDIO_L_ResetPlayerBuffer();
    }

    if (bytesRead < PLAYER_BUFFER_SIZE / 2) {
        AUDIO_L_ResetPlayerBuffer();
    }

}

void AUDIO_L_ResetPlayerBuffer() {
    f_close(&CURRENT_FILE);
    FILE_OFFSET = 0;
    AUDIO_P_End();
}
