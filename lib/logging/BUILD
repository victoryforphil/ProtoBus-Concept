cc_library(
    name = "pbus-logging",
    srcs = ["logging.cpp"],
    hdrs = ["logging.hpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "logging-test",
    srcs = ["logging_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = ["//lib/logging:pbus-logging",
           "@gtest//:main"],
)