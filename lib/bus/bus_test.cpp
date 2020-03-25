#include "gtest/gtest.h"

#include "bus.hpp"
#include "bus_map.hpp"
#include "lib/packet/packet.hpp"
#include "lib/packet/test.pb.h"

using namespace PBus;

TEST(bus,create)
{
    Logging::SetLogLevel(5);
    Bus* bus = new Bus(125,126);
    EXPECT_NE(bus, nullptr);
    delete bus;
}

TEST(bus,tag)
{
    Bus* bus = new Bus(125,126);
    EXPECT_EQ(bus->GetTag(), 125);
    delete bus;
}

TEST(bus,source)
{
    Bus* bus = new Bus(125,126);
    EXPECT_EQ(bus->GetSource(), 126);
    delete bus;
}

TEST(bus,packet)
{
    Bus* bus = new Bus(125,126);
    PBus::PacketTest::TestProto p;
    p.set_value3(415);
    bus->SubmitProtcolBuffer(&p);
    EXPECT_EQ(bus->GetCurrentPacket()->GetTag(), 125);
    EXPECT_EQ(bus->GetCurrentPacket()->GetSource(), 126);
    EXPECT_EQ(((PBus::PacketTest::TestProto*)bus->GetCurrentPacket()->GetProtocolBuffer())->value3(), 415);
    
    int size;
    bus->GetCurrentPacket()->GetBuffer(size);
    EXPECT_EQ(size, 3 + p.ByteSize());

    delete bus;
}

TEST(bus, map_register)
{
    Bus* bus = new Bus(125,126);
    EXPECT_NE(BusMap::GetBus(125), nullptr);
    delete bus;
}


