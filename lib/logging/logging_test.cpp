#include "gtest/gtest.h"

#include "logging.hpp"


TEST(log_level_test,content)
{
    PBus::Logging::SetLogLevel(4);
    int res = PBus::Logging::GetLogLevel();
    EXPECT_EQ(res,4);
}

TEST(log_debug_test,content)
{
    std::string output_;
    int res = PBus::Logging::Debug("TEST", "log_debug_test", "TEST!", output_);
    EXPECT_STREQ(output_.c_str(),"[DEBG] [TEST] (log_debug_test) TEST!");
    EXPECT_EQ(res,0);
}

TEST(log_info_test,content)
{
    std::string output_;
    int res = PBus::Logging::Info("TEST", "log_info_test", "TEST!", output_);
    EXPECT_STREQ(output_.c_str(),"[INFO] [TEST] (log_info_test) TEST!");
    EXPECT_EQ(res,0);
}

TEST(log_warn_test,content)
{
    std::string output_;
    int res = PBus::Logging::Warning("TEST", "log_warn_test", "TEST!", output_);
    EXPECT_STREQ(output_.c_str(),"[WARN] [TEST] (log_warn_test) TEST!");
    EXPECT_EQ(res,0);
}

TEST(log_error_test,content)
{
    std::string output_;
    int res =PBus::Logging::Error("TEST", "log_error_test", "TEST!", output_);
    EXPECT_STREQ(output_.c_str(),"[EROR] [TEST] (log_error_test) TEST!");
    EXPECT_EQ(res,1);
}