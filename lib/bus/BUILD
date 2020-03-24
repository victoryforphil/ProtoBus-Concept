cc_library(
    name = "pbus-bus",
    srcs = ["bus.cpp"],
    hdrs = ["bus.hpp"],
    deps = [
        "//lib/logging:pbus-logging",
        "//lib/packet:pbus-packet"
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "bus-test",
    srcs = ["bus.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//lib/bus:pbus-bus",
        "//lib/packet:pbus-packet",
        "@gtest//:main"
    ]
)

