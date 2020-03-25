cc_library(
    name = "pbus-transmission",
    srcs = ["transmitter.cpp"],
    hdrs = ["transmitter.hpp"],
    deps = [
        "//lib/logging:pbus-logging",
        "//lib/packet:pbus-packet"
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "tranmission-test",
    srcs = ["transmission_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//lib/bus:pbus-bus",
        "//lib/transmission:pbus-transmission",
        "@gtest//:main"
    ]
)

