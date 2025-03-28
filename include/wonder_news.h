#ifndef GUARD_WONDER_NEWS_H
#define GUARD_WONDER_NEWS_H

#include "global.h"

enum {
    WONDER_NEWS_NONE,
    WONDER_NEWS_RECV_FRIEND,
    WONDER_NEWS_RECV_WIRELESS,
    WONDER_NEWS_SENT,
};

void __attribute__((long_call)) WonderNews_SetReward(u32 newsType);
void __attribute__((long_call)) WonderNews_Reset(void);
void __attribute__((long_call)) WonderNews_IncrementStepCounter(void);

#endif //GUARD_WONDER_NEWS_H
