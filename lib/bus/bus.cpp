#include "bus.hpp"
#include "bus_map.hpp"
PBus::Bus::Bus(unsigned char tag, unsigned char source){
    mTag = tag;
    mSource = source;
   // mCurrentPacket = nullptr;

    BusMap::RegisterBus(this);

}
void PBus::Bus::SubmitProtcolBuffer(google::protobuf::Message* proto){


    Packet* newPacket = new Packet(mTag, mSource);
    mCurrentPacket = newPacket;
    mCurrentPacket->SetProtocolBuffer(proto);
    
}

PBus::Packet* PBus::Bus::GetCurrentPacket(){
    return mCurrentPacket;
}

unsigned char PBus::Bus::GetTag(){
    return mTag;
}

unsigned char PBus::Bus::GetSource(){
    return mSource;
    
}

PBus::Bus::~Bus(){

}