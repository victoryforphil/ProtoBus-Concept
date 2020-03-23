#include <iostream>
#include "lib/logging/logging.hpp"
#include "lib/packet/packet.hpp"
#include "lib/packet/test.pb.h"

int main(){
    PBus::Logging::Info("PacketDebug", "main","Packet Debug Application");

    PBus::PacketTest::TestProto p;
    PBus::Packet packet(255,200);

    packet.SetProtocolBuffer(&p);
    p.set_value1(true);
    p.set_value2(12);
    p.set_value3(131907310);
    int size = 0;
    unsigned char* buffer = packet.GetBuffer(size);
    

    PBus::Logging::Info("PacketDebug", "main","ProtcolBuffer Size:" + std::to_string(p.ByteSize()));
    PBus::Logging::Info("PacketDebug", "main","Packet Buffer Returned Size:" + std::to_string(size));
   // PBus::Logging::Info("PacketDebug", "main","Packet Buffer Measured Size:" + std::to_string(strlen(buffer)));
    for(int i=0;i<size;i++){
        std::cout <<std::to_string((int) buffer[i]) << std::endl;
    }
    return 0;
}

