/**
 * table_parser.cpp
 *
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-05 13:42
 * Brief: Defination Table Parser class.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */
#include "common.h"
#include "fs_reader.h"
#include "table_parser.h"
#include "parse_helper.h"

namespace baidu {
namespace inf {
namespace code_master {
bool TableParser::parse_line(FsReader* fs_reader, const std::string& delima)
{
    std::string line;
    if (fs_reader->read_line(line))
    {
        column_strs.clear();
        str_split(line, delima, column_strs);
    }
    else 
    {
        return false;
    }
    return true;
}

const std::vector<std::string>& TableParser::get_column_strs()
{
    return column_strs;
}
} // namespace code_master
} // namespace inf
} // namespace baidu
