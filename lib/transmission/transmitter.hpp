#ifndef _PBUS_TRANSMITTER_H_
#define _PBUS_TRANSMITTER_H_

#include "lib/packet/packet.hpp"

namespace PBus
{
    class Transmitter
    {
    private:
        /* data */
    public:
        Transmitter(/* args */);
        bool Transmit(Packet* packet);
        ~Transmitter();
    };
    

    
} // namespace Pbus

#endif