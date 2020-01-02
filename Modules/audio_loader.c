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
    FRESULT result = f_mkdir(AUDIO_DIRECTORY_PATH);
    if (result == FR_EXIST) {
        xprintf("Audio directory already exists.\r\n");
    }
    return result;
}

int AUDIO_L_ScanAudioDirectory() {
    DIR audioDirectory;
    FRESULT result;
    FILINFO fileInfo;
    int dir_count = 0;
 
    result = f_opendir(&audioDirectory, AUDIO_DIRECTORY_PATH);
    if (result == FR_OK)
    {
        result = f_readdir(&audioDirectory, &fileInfo);
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && dir_count < AUDIO_DIRECTORIES_LIMIT)
        {   if (fileInfo.fattrib & AM_DIR)
            {   xprintf("Found (%d) directory %s\r\n",++dir_count, fileInfo.fname);
                APP_STATE.DIRECTORIES[APP_STATE.DIR_COUNT] = malloc((strlen(fileInfo.fname)+1)*sizeof(char));
                strcpy(APP_STATE.DIRECTORIES[APP_STATE.DIR_COUNT], fileInfo.fname);
                APP_STATE.DIR_COUNT++;  }
            result = f_readdir(&audioDirectory, &fileInfo);
        }
        f_closedir(&audioDirectory);
        APP_STATE.SELECTED_DIR_INDEX = 0;
        APP_STATE.SELECTED_DIR_NAME = APP_STATE.DIRECTORIES[APP_STATE.SELECTED_DIR_INDEX];
        char path[30] = AUDIO_DIRECTORY_PATH;
        strcat(path, "/");
        strcat(path, APP_STATE.SELECTED_DIR_NAME);
        strcpy(APP_STATE.SELECTED_DIR_PATH, path);
        //xprintf ("Selected dir is: %s\r\n", APP_STATE.SELECTED_DIR_PATH);
    }
    else if (result == FR_NO_PATH) {
        xprintf("Empty audio directory will be created.\r\n");
        result = AUDIO_L_CreateAudioDirectory();
        if (result != FR_OK) {
            xprintf("Creation of audio directory has failed.\r\n");
            return -1;
        }
    } else if (result == FR_NO_FILE) {
        xprintf("Found zero directories.");
    }

    return dir_count;
}

int AUDIO_L_ScanDirectory() {
    xprintf("Scanning directory... \r\n");
    DIR audioDirectory;
    FRESULT result;
    FILINFO fileInfo;
    int count = 0;

    xprintf(APP_STATE.SELECTED_DIR_PATH);
    result = f_findfirst(&audioDirectory, &fileInfo, APP_STATE.SELECTED_DIR_PATH, "*.wav");
    if (result == FR_OK) {
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && count < AUDIO_FILES_LIMIT) {
            xprintf("Found (%d) wav file: %s\r\n", ++count, fileInfo.fname);
            APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT] = malloc((strlen(fileInfo.fname) + 1) * sizeof(char));
            strcpy(APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT], fileInfo.fname);
            APP_STATE.TRACKS_COUNT++;
            result = f_findnext(&audioDirectory, &fileInfo);
        }
    f_closedir(&audioDirectory);
    APP_STATE.SELECTED_TRACK_INDEX = 0;
    APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[0];
    }
    else if (result == FR_NO_PATH) {
        xprintf("There is no such directory.\r\n");    }
    else if (result == FR_NO_FILE) {
        xprintf("Found zero WAV files in this directory.");
    }
    return count;
    }


void AUDIO_L_PerformScan(void) {
    FRESULT result = AUDIO_L_CreateAudioDirectory();
    if (result == FR_OK || result == FR_EXIST) {
        AUDIO_L_ResetState();
        AUDIO_L_ScanAudioDirectory();
        AUDIO_L_ScanDirectory();
        APP_STATE.IS_DIRTY = 1; // to display recently loaded tracks
    }
}

void AUDIO_L_ResetState(void) {
    free(APP_STATE.DIRECTORIES);
    APP_STATE.DIRECTORIES = malloc (AUDIO_DIRECTORIES_LIMIT * sizeof(char*));
    APP_STATE.DIR_COUNT = 0;
    APP_STATE.SELECTED_DIR_INDEX = 0;
    APP_STATE.SELECTED_DIR_NAME = "";
    free(APP_STATE.TRACKS);
    APP_STATE.TRACKS = malloc(AUDIO_FILES_LIMIT * sizeof(char *));
    APP_STATE.TRACKS_COUNT = 0;
    APP_STATE.SELECTED_TRACK_INDEX = 0;
    APP_STATE.SELECTED_TRACK_NAME = "";
    APP_STATE.IS_PLAYING = 0;
    APP_STATE.IS_DIRTY = 1;
    APP_STATE.VOLUME = AUDIO_VOLUME_INIT;
}

void AUDIO_L_ToggleContinuousMode() {
    AUDIO_P_End();
    PLAYER_STATE.continuousModeOn = !PLAYER_STATE.continuousModeOn;
}

void AUDIO_L_LoadFileUnderButton(char *fileName, int buttonNumber) {
    FIL file;
    UINT _bytesRead;
    char *filePath = malloc(1000 * sizeof(char));

    if (sprintf(filePath, "%s/%s", APP_STATE.SELECTED_DIR_PATH, fileName) > 0) {
        if (f_open(&file, filePath, FA_READ) == FR_OK) {

            ButtonState *state = &APP_BUTTONS_STATE.configs[buttonNumber];
            state->size = f_size(&file);

            int initOffset = buttonNumber * BUFFER_LIMIT_PER_BUTTON;

            // retrieve essential info about file and skip WAV header
            f_lseek(&file, 22);
            f_read(&file, &AUDIO_BUFFER[initOffset], 4, &_bytesRead);
            state->channels = AUDIO_BUFFER[initOffset];
            state->sampleRate = (AUDIO_BUFFER[initOffset + 3] << 8) + AUDIO_BUFFER[2];
            f_lseek(&file, WAV_HEADER_LENGTH);

            // load onto buffer
            f_read(&file,
                   &AUDIO_BUFFER[buttonNumber * BUFFER_LIMIT_PER_BUTTON],
                   BUFFER_LIMIT_PER_BUTTON,
                   &_bytesRead
            );
            f_close(&file);

            // update app buttons state
            APP_BUTTONS_STATE.configs[buttonNumber].effectEnabled = effectInactive;
            APP_BUTTONS_STATE.configs[buttonNumber].trackPath = filePath;
            APP_BUTTONS_STATE.configs[buttonNumber].trackName = malloc(TEXT_DISPLAYED_MAXLENGTH * sizeof(char));
            sprintf(APP_BUTTONS_STATE.configs[buttonNumber].trackName, "%s", fileName);

            xprintf("Successfully read audio file: %s.\r\n", filePath);
        }
    } else {
        xprintf("An error has occurred when loading file onto buffer.\r\n");
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
