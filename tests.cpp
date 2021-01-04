#include "gtest/gtest.h"
#include "Base64_lib.h"
#include <vector>

TEST(codingMessage,SimpleTest) {
    std::vector<int> vec;
    std::string message = "Man is distinguished, not only by his reason, but by this singular "
                          "passion from other animals, which is a lust of the mind, that by a "
                          "perseverance of delight in the continued and indefatigable generation "
                          "of knowledge, exceeds the short vehemence of any carnal pleasure.";
    std::string expected = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpb"
                        "md1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQs"
                        "IHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0"
                        "aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgY"
                        "W55IGNhcm5hbCBwbGVhc3VyZS4=";

    ASSERT_TRUE(expected==(codingMessage(vec, message)));
}

TEST(DecodingBase64,SimpleTest) {
    std::string expected = "Man is distinguished, not only by his reason, but by this singular "
                          "passion from other animals, which is a lust of the mind, that by a "
                          "perseverance of delight in the continued and indefatigable generation "
                          "of knowledge, exceeds the short vehemence of any carnal pleasure.";
    std::string message = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpb"
                           "md1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQs"
                           "IHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0"
                           "aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgY"
                           "W55IGNhcm5hbCBwbGVhc3VyZS4=";

    ASSERT_TRUE(expected==(DecodingMessage(message)));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
