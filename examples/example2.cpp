/**
 * @file example2.cpp
 * @brief Example1: parse vector column.
 * @author Chen Kang (chenkang02@baidu.com)
 * @date 2015-10-05 21:17:00
 */

#include <string>
#include <iostream>
#include <stdio.h>

#include "parse_helper.h"
#include "common.h"
#include "fs_reader.h"
#include "table_parser.h"

namespace baidu {
namespace inf {
namespace code_master {

} // namespace code_master
} // namespace inf
} // namespace baidu

int main(int argc, char** argv)
{
    using baidu::inf::code_master::Status;
    using baidu::inf::code_master::SUCCESS;
    using baidu::inf::code_master::parse;
    using baidu::inf::code_master::TableParser;
    using baidu::inf::code_master::LocalFsReader;

    TableParser parser;
    LocalFsReader reader("../input/f1"); 
    reader.open();
    while (parser.parse_line(&reader, "\t"))
    {
        if (parser.get_column_strs().size() == 3)
        {
            std::string column1;
            std::vector<int> column2;
            float column3;
            if (SUCCESS != parser.get_value<std::string>(0, column1))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            if (SUCCESS != parser.get_vector_value<int>(1, column2))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            if (SUCCESS != parser.get_value<float>(0, column3))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            std::cout << column1 << "\t";
            std::cout << column2.size() << ":";
            for (size_t i = 0; i < column2.size();)
            {
                std::cout << column2[i];
                if (++i != column2.size())
                {
                    std::cout << ",";
                }
            }
            std::cout << "\t";
            std::cout << column3 << std::endl;
        }
    }
    reader.close();
    return 0;
}
