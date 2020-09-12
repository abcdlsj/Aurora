#include <errno.h>

#include "tcp_server.h"
#include "channel.h"
#include "acceptor.h"
#include "tcp_connection.h"

#include <vector>

TcpServer::TcpServer(EventLoop* pLoop)
    :_pAcceptor(NULL)
    ,_pLoop(pLoop)
    ,_pUser(NULL)
{
}

TcpServer::~TcpServer()
{
}

void TcpServer::start()
{
    _pAcceptor = new acceptor(_pLoop); // Memory Leak !!!
    _pAcceptor->setCallback(this);
    _pAcceptor->start();
}

void TcpServer::newConnection(int sockfd)
{
    TcpConnection* tcp = new TcpConnection(sockfd, _pLoop); // Memory Leak !!!
    _connections[sockfd] = tcp;
    tcp->setUser(_pUser);
    tcp->connectEstablished();
}

void TcpServer::setCallback(i_aurora_user* user)
{
    _pUser = user;
}
