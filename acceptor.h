#pragma once

#include "declear.h"
#include "define.h"
#include "i_channel_callback.h"

class acceptor : public IChannelCallback {
public:
    acceptor(EventLoop *pLoop);

    ~acceptor();

    void start();

    void setCallback(IAcceptorCallback *pCallback);

    virtual void handleRead();

    virtual void handleWrite();

private:
    int createAndListen();

    int _listenfd;
    Channel *_pSocketAChannel;
    IAcceptorCallback *_pCallback;
    EventLoop *_pLoop;
};

