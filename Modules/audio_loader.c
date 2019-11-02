//
// Created by olliekrk on 24.10.2019.
//

#include <ff.h>



#include <term_io.h>
#include "audio_loader.h"
#include "string.h"

FRESULT AUDIO_L_CreateAudioDirectory(void) {
    FRESULT result = f_mkdir(AUDIO_DIRECTORY_PATH);
    if (result == FR_EXIST){
        xprintf("Audio directory already exists.\r\n");
    }
    return result;
}

int AUDIO_L_ScanAudioDirectory(char **audioFilesNames) {
    DIR audioDirectory;
    FRESULT result;
    FILINFO fileInfo;
    int count = 0;
	
    result = f_findfirst(&audioDirectory, &fileInfo, AUDIO_DIRECTORY_PATH, "*.wav");
    if (result == FR_OK) {
        while (result == FR_OK && strlen(fileInfo.fname) > 0 && count < AUDIO_FILES_LIMIT) {
			audioFilesNames[count] = malloc(strlen(fileInfo.fname) * sizeof(char));
			audioFilesNames[count] = strcpy(audioFilesNames[count], fileInfo.fname);
            count++;
			result = f_findnext(&audioDirectory, &fileInfo);
        }
        f_closedir(&audioDirectory);
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
    char **audioFilesNames = malloc(AUDIO_FILES_LIMIT * sizeof(char *));
    FRESULT result = AUDIO_L_CreateAudioDirectory();
    if (result == FR_OK || result == FR_EXIST) {
        int filesFound = AUDIO_L_ScanAudioDirectory(audioFilesNames);
        xprintf("%d WAV files were found.\r\n", filesFound);
        for (int i = 0; i < filesFound; i++) {
            xprintf("Found WAV file no. %d: %s\r\n", i + 1, audioFilesNames[i]);
            free(audioFilesNames[i]);
        }
    }
    free(audioFilesNames);
}
