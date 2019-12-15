//
// Created by olliekrk on 24.11.2019.
//

#ifndef EMBEDDED_PLAYER_AUDIO_PLAYER_H
#define EMBEDDED_PLAYER_AUDIO_PLAYER_H

#include <ffconf.h>

#define AUDIO_QUEUE_SIZE 30
#define AUDIO_VOLUME_INIT 10
#define AUDIO_VOLUME_UNIT 5
#define AUDIO_VOLUME_LIMIT 90

extern osPoolId audioRequestsPool;
extern osMessageQId audioRequestsQueue;

typedef struct AudioRequest{
    int audioIndex;
} AudioRequest;

int AUDIO_P_ChangeFrequency(int);

void AUDIO_P_VolumeUp();

void AUDIO_P_VolumeDown();

void AUDIO_P_AddToQueue(int);

void AUDIO_P_Play(int);

void AUDIO_P_End();

#endif //EMBEDDED_PLAYER_AUDIO_PLAYER_H
