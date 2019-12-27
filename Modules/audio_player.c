//
// Created by olliekrk on 24.11.2019.
//

#include <term_io.h>
#include "audio_player.h"
#include "stm32746g_discovery_audio.h"
#include "audio_loader.h"
#include "controls.h"

osPoolId audioRequestsPool;
osMessageQId audioRequestsQueue;
int AudioQueueSize = 0;

int AUDIO_P_ChangeFrequency(int frequency) {
    int status = BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE1, APP_STATE.VOLUME, frequency);
    BSP_AUDIO_OUT_SetAudioFrameSlot(CODEC_AUDIOFRAME_SLOT_02);
    return status;
}

void AUDIO_P_VolumeUp() {
    if (APP_STATE.VOLUME < AUDIO_VOLUME_LIMIT) APP_STATE.VOLUME += AUDIO_VOLUME_UNIT;
    BSP_AUDIO_OUT_SetVolume(APP_STATE.VOLUME);
}

void AUDIO_P_VolumeDown() {
    if (APP_STATE.VOLUME > 0) APP_STATE.VOLUME -= AUDIO_VOLUME_UNIT;
    BSP_AUDIO_OUT_SetVolume(APP_STATE.VOLUME);
}

void AUDIO_P_AddToQueue(int audioIndex) {
    AudioRequest *request;
    request = osPoolAlloc(audioRequestsPool);
    request->audioIndex = audioIndex;
    osMessagePut(audioRequestsQueue, (uint32_t) request, 0);
    AudioQueueSize++;
}

void AUDIO_P_Play(int audioIndex) {
    AudioQueueSize--;
    int frequency = APP_BUTTONS_STATE.configs[audioIndex].sampleRate;
    if (AUDIO_P_ChangeFrequency(frequency) == AUDIO_OK) {
        xprintf("Playing: %d\r\n", audioIndex);
        BSP_AUDIO_OUT_Play(
                (uint16_t *) &AUDIO_BUFFER[audioIndex * BUFFER_LIMIT_PER_BUTTON],
                BUFFER_LIMIT_PER_BUTTON
        );
    }
}

void AUDIO_P_End() {
    APP_STATE.IS_PLAYING = 0;
    if (AudioQueueSize == 0) {
        BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);
    }
}
