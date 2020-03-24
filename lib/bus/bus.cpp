#include "bus.hpp"

PBus::Bus::Bus(unsigned char tag, unsigned char source){
    mTag = tag;
    mSource = source;
    mCurrentPacket = nullptr;
}
void PBus::Bus::SubmitProtcolBuffer(google::protobuf::Message* proto){
    if(mCurrentPacket != nullptr){
        delete mCurrentPacket;
    }

    Packet* newPacket = new Packet(mTag, mSource);
    newPacket->SetProtocolBuffer(proto);
}

PBus::Packet* PBus::Bus::GetCurrentPacket(){
    return mCurrentPacket;
}

PBus::Bus::~Bus(){
    if(mCurrentPacket != nullptr){
        delete mCurrentPacket;
    }
}