#ifndef DEAUTH_H
#define DEAUTH_H

#include <iostream>
#include <tins/tins.h>
using namespace Tins;

void usage(char *pname);

class deauth {
    Dot11Deauthentication _deauth;
public:
    void setAddr(Dot11::address_type dst_mac, Dot11::address_type src_mac);
    void setAddr(Dot11::address_type src_mac);
    void sendDeAuth(char *iface) const;
};

#endif // DEAUTH_H
