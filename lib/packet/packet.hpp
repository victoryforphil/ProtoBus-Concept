#ifndef _PBUS_PACKET_H_
#define _PBUS_PACKET_H_
#include <google/protobuf/message.h>
#include <string>
#include "lib/logging/logging.hpp"
namespace PBus
{


    class Packet
    {
    private:
        unsigned char mTag;
        unsigned char mSource;
        google::protobuf::Message* mProto;

    public:
        Packet(unsigned char tag,  unsigned char source);
        
        unsigned char GetTag();
        unsigned char GetSource();

        void SetProtocolBuffer( google::protobuf::Message* data);
        google::protobuf::Message* GetProtocolBuffer();

        unsigned char* GetBuffer(int &size);

    };
    

    
} // namespace PBus


#endif;

