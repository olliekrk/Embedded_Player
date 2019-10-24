//
// Created by olliekrk on 24.10.2019.
//

#ifndef EMBEDDED_PLAYER_AUDIO_LOADER_H
#define EMBEDDED_PLAYER_AUDIO_LOADER_H

#define AUDIO_STORAGE_PREFIX "1:/"

#define AUDIO_STORAGE_NAME "AudioDirectory"

#define AUDIO_DIRECTORY_PATH AUDIO_STORAGE_PREFIX AUDIO_STORAGE_NAME

#define AUDIO_FILES_LIMIT 10

FRESULT AUDIO_L_CreateAudioDirectory(void);

int AUDIO_L_ScanAudioDirectory(char **audioFilesNames);

void AUDIO_L_PerformScan(void);

#endif //EMBEDDED_PLAYER_AUDIO_LOADER_H
