#ifndef _IACCEPTORCALLBACK_H
#define _IACCEPTORCALLBACK_H

class IAcceptorCallBack {
public:
  void virtual newConnection(int sockfd);
};

#endif //_IACCEPTORCALLBACK_H