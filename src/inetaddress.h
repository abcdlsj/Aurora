//
// Created by abcdlsj on 2020/9/13.
//

#ifndef AURORA_INETADDRESS_H
#define AURORA_INETADDRESS_H

struct inet_address {
    int port;
};

struct inet_address *init_inet_address(int port);

#endif //AURORA_INETADDRESS_H
