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

AudioPlayerState PLAYER_STATE = {
        0,
        AUDIO_FREQUENCY_44K,
        0
};

int AUDIO_P_InitWithFrequency(int frequency) {
    int status = BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_HEADPHONE1, APP_STATE.VOLUME, frequency);
    PLAYER_STATE.frequency = frequency;
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
    PLAYER_STATE.queueSize++;
}

void AUDIO_P_Play(int audioIndex) {
    PLAYER_STATE.queueSize--;
    ButtonState buttonState = APP_BUTTONS_STATE.configs[audioIndex];
    int frequency = buttonState.sampleRate;
    int size = buttonState.size;
    if (size == 0) return;

    if (PLAYER_STATE.frequency != frequency) {
        AUDIO_P_InitWithFrequency(frequency);
    }

    APP_STATE.IS_PLAYING = 1;
    if (PLAYER_STATE.continuousModeOn == 0) {
        BSP_AUDIO_OUT_Play((uint16_t *) &AUDIO_BUFFER[audioIndex * BUFFER_LIMIT_PER_BUTTON], BUFFER_LIMIT_PER_BUTTON);
    } else {
        BSP_AUDIO_OUT_Play((uint16_t *) &PLAYER_BUFFER[0], PLAYER_BUFFER_SIZE);
    }
}

void AUDIO_P_End() {
    APP_STATE.IS_PLAYING = 0;
    BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW); // necessary
}

void AUDIO_P_PlayRoutine() {
    AudioRequest *request;
    osEvent event;

    if (!APP_STATE.IS_PLAYING) {
        event = osMessageGet(audioRequestsQueue, osWaitForever);
        if (event.status == osEventMessage) {
            request = event.value.p;

            if (PLAYER_STATE.continuousModeOn == 1) {
                AUDIO_L_StartPlayingFromButton(request->audioIndex);
            }

            AUDIO_P_Play(request->audioIndex);
            osPoolFree(audioRequestsPool, request);
        }
    } else if (PLAYER_STATE.continuousModeOn == 1) {
        AUDIO_L_UpdatePlayerBuffer();
    }
}
