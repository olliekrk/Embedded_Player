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

#define PLAYER_BUFFER_SIZE (1024 * 8)

#define AUDIO_BUFFER_SIZE (1024 * 1024)

#define WAV_HEADER_LENGTH 44

#define BUFFER_LIMIT_PER_BUTTON (AUDIO_BUFFER_SIZE / AUDIO_BUTTONS_COUNT)

#include <ff.h>

typedef enum BufferPos {
    BUFFER_OFFSET_NONE = 1,
    BUFFER_OFFSET_HALF = 2,
    BUFFER_OFFSET_FULL = 3,
} BufferPos;

extern int FILE_OFFSET;
extern BufferPos BUFFER_OFFSET;
extern FIL CURRENT_FILE;

extern uint8_t PLAYER_BUFFER[PLAYER_BUFFER_SIZE] __attribute__((section(".sdram")));
extern uint8_t AUDIO_BUFFER[AUDIO_BUFFER_SIZE] __attribute__((section(".sdram")));

FRESULT AUDIO_L_CreateAudioDirectory(void);

int AUDIO_L_ScanAudioDirectory(void);

void AUDIO_L_PerformScan(void);

void AUDIO_L_ResetState(void);

void AUDIO_L_LoadFileUnderButton(char *, int);

// CONTINUOUS PLAY

void AUDIO_L_ToggleContinuousMode();

void AUDIO_L_StartPlayingFromButton(int);

void AUDIO_L_StartPlayingFromFile(const char *);

void AUDIO_L_UpdatePlayerBuffer();

void AUDIO_L_ResetPlayerBuffer();

#endif //EMBEDDED_PLAYER_AUDIO_LOADER_H
