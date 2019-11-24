//
// Created by olliekrk on 24.11.2019.
//

#ifndef EMBEDDED_PLAYER_AUDIO_PLAYER_H
#define EMBEDDED_PLAYER_AUDIO_PLAYER_H

#include <ffconf.h>

#define AUDIO_VOLUME 50
#define AUDIO_QUEUE_SIZE 20

extern osPoolId audioRequestsPool;
extern osMessageQId audioRequestsQueue;
extern int isPlaying;

typedef struct AudioRequest{
    int audioIndex;
} AudioRequest;

int AUDIO_P_Reinitialize(int);

void AUDIO_P_AddToQueue(int);

void AUDIO_P_Play(int);

#endif //EMBEDDED_PLAYER_AUDIO_PLAYER_H
