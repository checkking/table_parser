/**
 * @file test_fs_reader.cpp
 * @author Chen Kang (chenkang02@baidu.com)
 * @version 1.0
 */
#include <string>
#include <gtest/gtest.h>

#include "fs_reader.h"

namespace baidu {
namespace inf {
namespace code_master {
TEST(local_fs_reder, read_line)
{
    LocalFsReader reader("../input/f1");

    reader.open();
    std::string str1;
    bool status = reader.read_line(str1);
    ASSERT_TRUE(status);
    EXPECT_EQ(str1, "xx\t2:1,1\t0.1");
    std::string str2;
    status = reader.read_line(str2);
    ASSERT_TRUE(status);
    EXPECT_EQ(str2, "yy\t0:\t9.99");
    std::string str3;
    status = reader.read_line(str3);
    ASSERT_FALSE(status);
    reader.close();
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
