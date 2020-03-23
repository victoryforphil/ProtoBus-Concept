#include "gtest/gtest.h"

#include "ipc.hpp"

TEST(message_test,content)
{
  PBus::IPC mIpc;
  EXPECT_EQ(mIpc.CreateHandle(),true);
}