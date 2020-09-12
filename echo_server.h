#pragma once
#include "i_aurora_user.h"
#include "i_run.h"
#include "tcp_server.h"
#include "thread_pool.h"

class EchoServer : public i_aurora_user
                   , public IRun2
{
public:
    EchoServer(EventLoop* pLoop);
    ~EchoServer();
    void start();
    virtual void onConnection(TcpConnection* pCon);
    virtual void onMessage(TcpConnection* pCon, Buffer* pBuf);
    virtual void onWriteComplate(TcpConnection* pCon);

    virtual void run2(const string& str, void* tcp);
private:
    int fib(int n);
    EventLoop* _pLoop;
    TcpServer _pServer;
    ThreadPool _threadpool;
    int _timer;
    int _index;
};
