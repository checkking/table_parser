/**
 * @file test_common.cpp
 * @author Chen Kang (chenkang02@baidu.com)
 * @version 1.0
 */
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "common.h"

namespace baidu {
namespace inf {
namespace code_master {
using std::vector;

TEST(common, str_split)
{
    std::string str1 = "";
    vector<std::string> vec1;
    str_split(str1, ",", vec1);
    EXPECT_EQ(0, vec1.size());

    std::string str2 = "1";
    vector<std::string> vec2;
    str_split(str2, ",", vec2);
    EXPECT_EQ(1, vec2.size());
    EXPECT_EQ("1", vec2[0]);

    std::string str3 = "1\t2\t3";
    vector<std::string> vec3;
    str_split(str3, "\t", vec3);
    EXPECT_EQ(3, vec3.size());
    EXPECT_EQ("2", vec3[1]);
}
} // namespace code_master
} // namespace inf
} // namespace baidu

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    int test_code = RUN_ALL_TESTS();
    return test_code;
}
