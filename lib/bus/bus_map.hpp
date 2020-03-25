#ifndef _PBUS_BUS_MAP_H_
#define _PBUS_BUS_MAP_H_
#include "lib/logging/logging.hpp"

#include "lib/transmission/transmitter.hpp"
#include "bus.hpp"
#include <google/protobuf/message.h>
#include <vector>
namespace PBus
{
    class BusMap
    {
    private:
        static Bus** mBusses; // Store all possible busses, use tag as index, max 255
        static std::vector<Transmitter*> mTransmitters;
    public:
        static void RegisterBus(Bus* bus);
        static void RegisterTransmitter(Transmitter* transmitter);
        static Bus* GetBus(unsigned char tag);
        static void SubmitPacket(Packet* packet); // Called from transmitters when they recieve a packet
        static void BroadcastBus(Bus* bus); // Called by busses when they recieve a packet update.
    };

    
} // namespace PBus




#endif