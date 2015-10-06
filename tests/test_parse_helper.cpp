/**
 * @file test_parse_helper.cpp
 * @author Chen Kang (chenkang02@baidu.com)
 * @version 1.0
 */
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "parse_helper.h"

namespace baidu {
namespace inf {
namespace code_master {

using std::vector;

TEST(parse_helper, parse_to_int)
{
    std::string str1 = "18";
    int result;
    Status status;
    status = parse(str1, result);
    ASSERT_EQ(SUCCESS, status);
    EXPECT_EQ(18, result);

    status = parse("", result);
    ASSERT_EQ(COLUMN_EMPTY_ERROR, status);
    EXPECT_EQ(18, result);
}

TEST(parse_helper, parse_to_string)
{
    std::string str1 = "";
    std::string result1;
    std::string str2 = "123";
    std::string result2;
    std::string str3 = " ";
    std::string result3;
    Status status;

    status = parse(str1, result1);
    ASSERT_EQ(COLUMN_EMPTY_ERROR, status);
    status = parse(str2, result2);
    ASSERT_EQ(SUCCESS, status);
    EXPECT_EQ("123", result2);
    status = parse(str3, result3);
    ASSERT_EQ(SUCCESS, status);
    EXPECT_EQ(" ", result3);
}

TEST(parse_helper, parse_to_float)
{
    std::string str1 = "";
    float result1;
    std::string str2 = ".2";
    float result2;
    std::string str3 = "0.22f";
    float result3;
    Status status;
    status = parse(str1, result1);
    ASSERT_EQ(COLUMN_EMPTY_ERROR, status);
    status = parse(str2, result2);
    ASSERT_EQ(SUCCESS, status);
    EXPECT_FLOAT_EQ(0.2, result2);
    status = parse(str3, result3);
    ASSERT_EQ(SUCCESS, status);
    EXPECT_FLOAT_EQ(0.22, result3);
}

TEST(parse_helper, parse_to_vector)
{
    std::string str1 = "0:";
    vector<std::string> vec1;
    Status status1 = parse_to_vector<std::string>(str1, vec1);
    ASSERT_EQ(SUCCESS, status1);
    EXPECT_EQ(vec1.size(), 0);
    
    std::string str2 = "0:1";
    vector<int> vec2;
    Status status2 = parse_to_vector<int>(str2, vec2);
    EXPECT_EQ(COLUMN_VECTOR_ERROR, status2);

    std::string str3 = "1:1";
    vector<int> vec3;
    Status status3 = parse_to_vector<int>(str3, vec3);
    ASSERT_EQ(SUCCESS, status3);
    EXPECT_EQ(vec3.size(), 1);
    EXPECT_EQ(vec3[0], 1);
    
    std::string str4 = "3:0.99,1.00,0.00";
    vector<float> vec4;
    Status status4 = parse_to_vector<float>(str4, vec4);
    ASSERT_EQ(SUCCESS, status4);
    EXPECT_EQ(vec4.size(), 3);
    EXPECT_FLOAT_EQ(vec4[1], 1.00);
    EXPECT_FLOAT_EQ(vec4[2], 0.00);

    std::string str5 = "1:hello";
    vector<std::string> vec5;
    Status status5 = parse_to_vector<std::string>(str5, vec5);
    ASSERT_EQ(SUCCESS, status5);
    ASSERT_EQ(vec5.size(), 1);
    EXPECT_EQ("hello", vec5[0]);

    std::string str6 = "12";
    vector<int> vec6;
    Status status6 = parse_to_vector<int>(str6, vec6);
    EXPECT_EQ(COLUMN_VECTOR_ERROR, status6);
}

TEST(parse_helper, check_right_vector) {
    std::string str1 = "";
    vector<std::string> vec1;
    Status status = check_right_vector(str1, vec1);
    EXPECT_EQ(status, COLUMN_VECTOR_ERROR);
    std::string str2 = "1";
    vector<std::string> vec2;
    status = check_right_vector(str2, vec2);
    EXPECT_EQ(status, COLUMN_VECTOR_ERROR);
    std::string str3 = "3:0,1";
    vector<std::string> vec3;
    status = check_right_vector(str3, vec3);
    EXPECT_EQ(status, COLUMN_VECTOR_ERROR);
    std::string str4 = "2:1,1";
    vector<std::string> vec4;
    status = check_right_vector(str4, vec4);
    EXPECT_EQ(vec4[0], "1");
    EXPECT_EQ(vec4[1], "1");
    EXPECT_EQ(SUCCESS, status);
    std::string str5 = "0:";
    vector<std::string> vec5;
    status = check_right_vector(str5, vec5);
    EXPECT_EQ(SUCCESS, status);
    EXPECT_EQ(0, vec5.size());
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
