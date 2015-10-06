/**
 * @file example1.cpp
 * @brief Example1: parse user defined struct Item
 * @author Chen Kang (chenkang02@baidu.com)
 * @date 2015-10-05 10:17:00
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

const size_t g_max_item_size = 256;

struct Item {
    std::string item_id;
    std::string item_name;
    float item_weight;
    int item_size;
    std::string to_string()
    {
        char buffer[g_max_item_size];
        sprintf(buffer, "%s\t%s\t%f\t%d", 
                item_id.c_str(), item_name.c_str(), item_weight, item_size);
        std::string str;
        str.assign(buffer);

        return str;
    }
};

typedef struct Item Item;

template<>
Status parse(const std::string& str, Item& result)
{
    if (COLUMN_EMPTY_ERROR == check_not_empty(str)) {
        return COLUMN_EMPTY_ERROR;
    }
    std::vector<std::string> vec;
    str_split(str, ",", vec);
    Status status = parse<std::string>(vec[0], result.item_id);
    if (status != SUCCESS)
    {   
        return status;
    }
    status = parse<std::string>(vec[1], result.item_name);
    if (status != SUCCESS)
    {   
        return status;
    }
    status = parse<float>(vec[2], result.item_weight);
    if (status != SUCCESS)
    {   
        return status;
    }
    status = parse<int>(vec[3], result.item_size);
    if (status != SUCCESS)
    {   
        return status;
    }

    return SUCCESS;
}

} // namespace code_master
} // namespace inf
} // namespace baidu

int main(int argc, char** argv)
{
    using baidu::inf::code_master::Item;
    using baidu::inf::code_master::Status;
    using baidu::inf::code_master::SUCCESS;
    using baidu::inf::code_master::parse;
    using baidu::inf::code_master::TableParser;
    using baidu::inf::code_master::LocalFsReader;
    
    TableParser parser;
    LocalFsReader reader("../input/f2");
    reader.open();
    while (parser.parse_line(&reader, "\t"))
    {
        if (parser.get_column_strs().size() == 3)
        {
            int line_num = 0;
            std::string time_stamp;
            Item item;
            if (SUCCESS != parser.get_value<int>(0, line_num))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            if (SUCCESS != parser.get_value<std::string>(1, time_stamp))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            if (SUCCESS != parser.get_value<Item>(2, item))
            {
                std::cout << "Info: parse a line failed !" << std::endl;
                continue;
            }
            std::cout << line_num << "\t" 
                        << time_stamp << "\t" << item.to_string() << std::endl;
        }
    }
    reader.close();

    return 0;
}
