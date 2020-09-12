#pragma once
class IAcceptorCallback
{
    public:
        virtual void newConnection(int sockfd) = 0;
};

