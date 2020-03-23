cc_library(
    name = "pbus-ipc",
    srcs = ["ipc.cpp"],
    hdrs = ["ipc.hpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "ipc-test",
    srcs = ["ipc_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = ["//lib/ipc:pbus-ipc",
           "@gtest//:main"],
)