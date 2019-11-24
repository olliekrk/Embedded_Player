//
// Created by olliekrk on 24.10.2019.
//

#ifndef EMBEDDED_PLAYER_AUDIO_LOADER_H
#define EMBEDDED_PLAYER_AUDIO_LOADER_H

#define AUDIO_STORAGE_PREFIX "1:/"

#define AUDIO_STORAGE_NAME "AudioDirectory"

#define AUDIO_DIRECTORY_PATH AUDIO_STORAGE_PREFIX AUDIO_STORAGE_NAME

#define AUDIO_BUTTONS_COUNT 8

#define AUDIO_FILES_LIMIT 10

#define AUDIO_OUT_BUFFER_SIZE 8192

#define MASS_STORAGE_BUF_SIZE ( 1024 * 1024 )

#define BUFFER_LIMIT_PER_BUTTON (MASS_STORAGE_BUF_SIZE / AUDIO_BUTTONS_COUNT)

#include <ff.h>

extern uint8_t TMP_BUFFER[AUDIO_OUT_BUFFER_SIZE];

// changed from uint32_t
extern uint8_t AUDIO_BUFFER[MASS_STORAGE_BUF_SIZE] __attribute__((section(".sdram")));

FRESULT AUDIO_L_CreateAudioDirectory(void);

int AUDIO_L_ScanAudioDirectory(void);

void AUDIO_L_PerformScan(void);

void AUDIO_L_ResetState(void);

void AUDIO_L_LoadFileUnderButton(char*, int);

#endif //EMBEDDED_PLAYER_AUDIO_LOADER_H
