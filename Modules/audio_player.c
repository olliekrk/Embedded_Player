//
// Created by olliekrk on 24.11.2019.
//

#include <term_io.h>
#include "audio_player.h"
#include "stm32746g_discovery_audio.h"
#include "audio_loader.h"

osPoolId audioRequestsPool;
osMessageQId audioRequestsQueue;
int isPlaying;

int AUDIO_P_Reinitialize(int frequency) {
    int status = BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE1, AUDIO_VOLUME, frequency);
    BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);
    return status;
}

void AUDIO_P_AddToQueue(int audioIndex) {
    AudioRequest *request;
    request = osPoolAlloc(audioRequestsPool);
    request->audioIndex = audioIndex;
    osMessagePut(audioRequestsQueue, (uint32_t) request, 0);
}

void AUDIO_P_Play(int audioIndex) {
	if (isPlaying) {
        BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
    }

    isPlaying = 1;
    BSP_AUDIO_OUT_Play(
            (uint16_t *) &AUDIO_BUFFER[audioIndex * BUFFER_LIMIT_PER_BUTTON],
            BUFFER_LIMIT_PER_BUTTON
    );
}

void AUDIO_P_End(){
	isPlaying = 0;
}
