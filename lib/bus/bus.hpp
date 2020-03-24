#ifndef _PBUS_BUS_H_
#define _PBUS_BUS_H_
#include "lib/logging/logging.hpp"
#include "lib/packet/packet.hpp"
#include <google/protobuf/message.h>
namespace PBus
{
    class Bus
    {
    private:
        Packet* mCurrentPacket;
        unsigned char mTag;
        unsigned char mSource;
    public:
        Bus(unsigned char tag, unsigned char source);
        void SubmitProtcolBuffer(google::protobuf::Message* proto);
        Packet* GetCurrentPacket();
        ~Bus();
    };
    

        
} // namespace PBus


#endif