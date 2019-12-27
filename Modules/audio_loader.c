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

uint8_t AUDIO_BUFFER[MASS_STORAGE_BUF_SIZE] __attribute__((section(".sdram"))) __attribute__((unused));

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
    int count = 0;

    result = f_findfirst(&audioDirectory, &fileInfo, AUDIO_DIRECTORY_PATH, "*.wav");
    if (result == FR_OK) {
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && count < AUDIO_FILES_LIMIT) {
            xprintf("Found (%d) wav file: %s\r\n", ++count, fileInfo.fname);

            APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT] = malloc((strlen(fileInfo.fname) + 1) * sizeof(char));
            strcpy(APP_STATE.TRACKS[APP_STATE.TRACKS_COUNT], fileInfo.fname);
            APP_STATE.TRACKS_COUNT++;
            result = f_findnext(&audioDirectory, &fileInfo);
        }
        f_closedir(&audioDirectory);

        // Set first track
        APP_STATE.SELECTED_TRACK_INDEX = 0;
        APP_STATE.SELECTED_TRACK_NAME = APP_STATE.TRACKS[0];

    } else if (result == FR_NO_PATH) {
        xprintf("Empty audio directory will be created.\r\n");
        result = AUDIO_L_CreateAudioDirectory();
        if (result != FR_OK) {
            xprintf("Creation of audio directory has failed.\r\n");
            return -1;
        }
    } else if (result == FR_NO_FILE) {
        xprintf("Found zero WAV files.");
    }

    return count;
}

void AUDIO_L_PerformScan(void) {
    FRESULT result = AUDIO_L_CreateAudioDirectory();
    if (result == FR_OK || result == FR_EXIST) {
        AUDIO_L_ResetState();
        AUDIO_L_ScanAudioDirectory();
        APP_STATE.IS_DIRTY = 1; // to display recently loaded tracks
    }
}

void AUDIO_L_ResetState(void) {
    free(APP_STATE.TRACKS);
    APP_STATE.TRACKS = malloc(AUDIO_FILES_LIMIT * sizeof(char *));
    APP_STATE.TRACKS_COUNT = 0;
    APP_STATE.SELECTED_TRACK_INDEX = 0;
    APP_STATE.SELECTED_TRACK_NAME = "";
    APP_STATE.IS_PLAYING = 0;
    APP_STATE.IS_DIRTY = 1;
    APP_STATE.VOLUME = AUDIO_VOLUME_INIT;
}

void AUDIO_L_LoadFileUnderButton(char *fileName, int buttonNumber) {
    FIL file;
    UINT _bytesRead;
    char *filePath = malloc(1000 * sizeof(char));

    if (sprintf(filePath, "%s/%s", AUDIO_DIRECTORY_PATH, fileName) > 0) {
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
            APP_BUTTONS_STATE.configs[buttonNumber].trackName = malloc(TEXT_DISPLAYED_MAXLENGTH * sizeof(char));
            sprintf(APP_BUTTONS_STATE.configs[buttonNumber].trackName, "%s", fileName);

            xprintf("Successfully read audio file: %s of size %u bytes.\r\n", filePath, _bytesRead);
        }
    } else {
        xprintf("An error has occurred when loading file onto buffer.\r\n");
    }

    free(filePath);
}

/* How to introduce this:
 * - add call to this inside audioPlayerTask loop (in else {})
 * - make APP_BUTTONS_STATE hold also full file name + shortened for display
 * - taking message from queue must:
 * -    call ...UpdateCurrentFile inside audioPlayerTask loop (in if {})
 * -    set APP_STATE.IS_PLAYING to 1
 * -    reinitialize BSP with correct frequency
 * -    change buffer reference and buffer size in AUDIO_P_Play()
 */
void AUDIO_L_UpdateBuffer() {
    uint32_t bytesRead;
    FRESULT result;

    switch (BUFFER_OFFSET) {
        case BUFFER_OFFSET_HALF:
            result = f_read(&CURRENT_FILE,
                            &AUDIO_BUFFER[0],
                            AUDIO_OUT_BUFFER_SIZE / 2,
                            (void *) &bytesRead);
            break;
        case BUFFER_OFFSET_FULL:
            result = f_read(&CURRENT_FILE,
                            &AUDIO_BUFFER[AUDIO_OUT_BUFFER_SIZE / 2],
                            AUDIO_OUT_BUFFER_SIZE / 2,
                            (void *) &bytesRead);
            break;
        default:
            return;
    }

    if (result == FR_OK) {
        BUFFER_OFFSET = BUFFER_OFFSET_NONE;
        FILE_OFFSET += bytesRead;
    } else {
        xprintf("Stop on error!\r\n");
        BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
        AUDIO_L_ResetBuffer();
    }

    if (bytesRead < AUDIO_OUT_BUFFER_SIZE / 2 && FILE_OFFSET) {
        xprintf("Stop ok.\r\n");
        AUDIO_L_ResetBuffer();
    }

}

void AUDIO_L_ResetBuffer() {
    f_close(&CURRENT_FILE);
    BUFFER_OFFSET = BUFFER_OFFSET_NONE;
    FILE_OFFSET = 0;
    APP_STATE.IS_PLAYING = 0;
}

void AUDIO_L_UpdateCurrentFile(const char *fileName) {
    char *filePath = malloc(1000 * sizeof(char));
    int bytesRead;

    if (sprintf(filePath, "%s/%s", AUDIO_DIRECTORY_PATH, fileName) > 0) {
        if (f_open(&CURRENT_FILE, filePath, FA_READ) == FR_OK) {
            f_lseek(&CURRENT_FILE, WAV_HEADER_LENGTH); // skip the header
            f_read(&CURRENT_FILE, &AUDIO_BUFFER[0], AUDIO_OUT_BUFFER_SIZE, (void *) &bytesRead);

            FILE_OFFSET = WAV_HEADER_LENGTH + bytesRead;
            BUFFER_OFFSET = BUFFER_OFFSET_NONE;
        }
    }

    free(filePath);
}