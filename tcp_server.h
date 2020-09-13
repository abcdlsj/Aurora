#pragma once

#include <sys/epoll.h>

#include "declear.h"
#include "define.h"
#include "i_acceptor_callback.h"
#include "i_aurora_user.h"

#include <map>

using namespace std;

class TcpServer : public IAcceptorCallback {
public:
    TcpServer(EventLoop *pLoop);

    ~TcpServer();

    void start();

    void setCallback(i_aurora_user *pUser);

    virtual void newConnection(int sockfd);

private:
    struct epoll_event _events[MAX_EVENTS];
    map<int, TcpConnection *> _connections;
    acceptor *_pAcceptor;
    EventLoop *_pLoop;
    i_aurora_user *_pUser;
};
