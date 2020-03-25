cc_library(
    name = "pbus-bus",
    srcs = ["bus.cpp", "bus_map.cpp"],
    hdrs = ["bus.hpp", "bus_map.hpp"],
    deps = [
        "//lib/logging:pbus-logging",
        "//lib/packet:pbus-packet",
        "//lib/transmission:pbus-transmission"
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "bus-test",
    srcs = ["bus_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//lib/bus:pbus-bus",
        "//lib/packet:pbus-packet",
        "@gtest//:main"
    ]
)

