#ifndef _IAURORAUSER_H
#define _IAURORAUSER_H

#include "declear.h"
#include <string>
using namespace std;
class IAuraroUser {
public:
  void virtual onConnection(TcpConnection *pCon) = 0;
  void virtual onMessage(TcpConnection *pCon, const string &data) = 0;
};

#endif // _IAURORAUSER_H