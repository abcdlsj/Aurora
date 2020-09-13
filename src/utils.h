//
// Created by abcdlsj on 2020/9/13.
//

#ifndef AURORA_UTILS_H
#define AURORA_UTILS_H

#include "event_loop.h"

void assertInSameThread(struct event_loop *eventLoop);

//1： same thread: 0： not the same thread
int isInSameThread(struct event_loop *eventLoop);

#endif //AURORA_UTILS_H
