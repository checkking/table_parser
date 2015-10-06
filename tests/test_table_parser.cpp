/**
 * @file test_table_parser.cpp
 * @author Chen Kang (chenkang02@baidu.com)
 * @version 1.0
 */
#include <string>
#include <gtest/gtest.h>

#include "table_parser.h"
#include "fs_reader.h"
#include "common.h"

namespace baidu {
namespace inf {
namespace code_master {
TEST(table_parser, parser_line)
{
    TableParser parser;
    LocalFsReader reader("../input/f1"); 
    reader.open();
    while (parser.parse_line(&reader, "\t"))
    {
        const std::vector<std::string> column_strs = parser.get_column_strs();
        EXPECT_EQ(column_strs.size(), 3);
    }

    reader.close();
}

TEST(table_parser, get_value)
{
    TableParser parser;
    LocalFsReader reader("../input/f1"); 
    reader.open();
    bool status = parser.parse_line(&reader, "\t");
    ASSERT_TRUE(status);

    std::string column1;
    std::vector<int> column2; 
    float column3;

    size_t idx = 0;
    ASSERT_TRUE(SUCCESS == parser.get_value<std::string>(idx, column1));
    EXPECT_EQ("xx", column1);
    idx = 1;
    ASSERT_TRUE(SUCCESS == parser.get_vector_value<int>(idx, column2));
    ASSERT_EQ(2, column2.size());
    EXPECT_EQ(1, column2[0]);
    idx = 2;
    ASSERT_TRUE(SUCCESS == parser.get_value<float>(idx, column3));
    EXPECT_FLOAT_EQ(0.1, column3);
    
    status = parser.parse_line(&reader, "\t");
    ASSERT_TRUE(status);
    column2.clear();
    ASSERT_TRUE(SUCCESS == parser.get_vector_value<int>(1, column2));
    EXPECT_EQ(0, column2.size());
    
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
