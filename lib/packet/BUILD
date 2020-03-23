cc_library(
    name = "pbus-packet",
    srcs = ["packet.cpp"],
    hdrs = ["packet.hpp"],
    deps = [
        ":test_cc_proto",
        "//lib/logging:pbus-logging"
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "packet-test",
    srcs = ["packet_test.cpp"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "//lib/packet:pbus-packet",
        "@gtest//:main",
        ":test_cc_proto"
    ],
)

cc_proto_library(
    name = "test_cc_proto",
    deps = [":test_proto"],
    visibility = ["//visibility:public"],
)
proto_library(
    name = "test_proto",
    srcs = ["test.proto"],
    deps = [
        "@com_google_protobuf//:any_proto",
    ],
)