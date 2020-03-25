#include "bus_map.hpp"

PBus::Bus** PBus::BusMap::mBusses = new PBus::Bus*[255];
std::vector<PBus::Transmitter*> PBus::BusMap::mTransmitters;


void PBus::BusMap::RegisterBus(Bus* bus){
    PBus::Logging::Info("BusMap", "RegisterBus", "Registering Bus: " + std::to_string(bus->GetTag()));
    mBusses[bus->GetTag()] = bus;
}

void PBus::BusMap::SubmitPacket(PBus::Packet* packet){
    Bus* _bus = GetBus(packet->GetTag());

    if(_bus != nullptr){
        _bus->SubmitProtcolBuffer(packet->GetProtocolBuffer());
    }else{
        Logging::Warning("BusMap", "SubmitPacket", "Got Packet with no registered bus.");
    }
}
void PBus::BusMap::BroadcastBus(Bus* bus){
    for(int i=0;i<mTransmitters.size();i++){
        if(mTransmitters[i]->Transmit(bus->GetCurrentPacket())){
            //
        }
    }
}

PBus::Bus* PBus::BusMap::GetBus(unsigned char tag){
    return mBusses[tag];
}