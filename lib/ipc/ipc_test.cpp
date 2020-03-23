#include "gtest/gtest.h"

#include "ipc.hpp"

TEST(message_test,content)
{
    IPC mIpc;
  EXPECT_EQ(mIpc.CreateHandle(),true);
}