#include "gtest/gtest.h"

#include "packet.hpp"
#include "lib/packet/test.pb.h"

TEST(proto_compile,content)
{
    PBus::PacketTest::TestProto p;
    p.set_value1(true);
    EXPECT_EQ(p.value1(),true);
}

TEST(proto_set,content)
{
    PBus::PacketTest::TestProto p;
    PBus::Packet packet(2,2);
    packet.SetProtocolBuffer(&p);
    p.set_value2(415);
    EXPECT_EQ(((PBus::PacketTest::TestProto*)packet.GetProtocolBuffer())->value2(),415);
}


TEST(packet_buffer,content)
{
    PBus::PacketTest::TestProto p;
    PBus::Packet packet(2,0);
    packet.SetProtocolBuffer(&p);
    p.set_value2(415);
    int size=0;
    unsigned char* buffer = packet.GetBuffer(size);

    EXPECT_EQ(size, p.ByteSize() + 3);
}

TEST(packet_buffer_empty,content)
{
    PBus::Packet packet(2,0);
    int size=0;
    unsigned char* buffer = packet.GetBuffer(size);

    EXPECT_EQ(size,  3);
}

