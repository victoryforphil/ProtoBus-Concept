#include "packet.hpp"


PBus::Packet::Packet(unsigned char tag, unsigned char source){
    mTag = tag;
    mSource = source;
    mProto = nullptr;
    PBus::Logging::Debug("Packet-"+std::to_string((int)GetTag()), "constructor", "Created new packet!");
}
PBus::Packet::~Packet(){
    if(mProto != nullptr){
        //delete mProto;
    }
}

void PBus::Packet::SetProtocolBuffer( google::protobuf::Message* proto){
    PBus::Logging::Debug("Packet-"+std::to_string((int)GetTag()), "SetProtocolBuffer", "Setting Protocol Buffer");
    mProto = proto;
  
}

unsigned char PBus::Packet::GetTag(){
    return mTag;
}

unsigned char PBus::Packet::GetSource(){
    return mSource;
}

google::protobuf::Message* PBus::Packet::GetProtocolBuffer(){
    return mProto;
}

unsigned char* PBus::Packet::GetBuffer(int &size){
    
    if(mProto == nullptr){
        unsigned char* _blankBuffer = new unsigned char[3];
        _blankBuffer[0] = GetTag();
        _blankBuffer[1] = GetSource();
        _blankBuffer[2] = 0;
        size = 3;
        return _blankBuffer;
    }

    char _protoSize = mProto->ByteSize();
    PBus::Logging::Debug("Packet-"+std::to_string((int)GetTag()), "GetBuffer", "ProtoBuff Size: " + std::to_string((int)_protoSize) );
    char* _protoBuffer = new char[_protoSize];
    mProto->SerializeToArray(_protoBuffer, _protoSize);
    unsigned char* _packetBuffer = new unsigned char[_protoSize + 3];
    _packetBuffer[0] = GetTag();
    _packetBuffer[1] = GetSource();
    _packetBuffer[2] = _protoSize;
    size = _protoSize + 3;
    memcpy( _packetBuffer + 3, _protoBuffer, _protoSize );
    return _packetBuffer;
}