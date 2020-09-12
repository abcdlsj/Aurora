#pragma once

#include <sys/epoll.h>

#include "declear.h"
#include "define.h"

#include <vector>
using namespace std;

class Epoll
{
public:
    Epoll();
    ~Epoll();
    void poll(vector<Channel*>* pChannels);
    void update(Channel* pChannel);
private:
    int _epollfd;
    struct epoll_event _events[MAX_EVENTS];
};
