#ifndef _ICHANNELCALLBACK_H
#define _ICHANNELCALLBACK_H
class IChannelCallBack {
public:
  void virtual OnIn(int sockfd){};
};

#endif //_ICHANNELCALLBACK_H
