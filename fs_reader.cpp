/**
 * fs_reader.cpp
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-05 14:07:00
 * Brief: Defination fs reader class.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */

#include "fs_reader.h"

namespace baidu {
namespace inf {
namespace code_master {
bool LocalFsReader::open() {
    if (_file_name == "")
    {
        return false;
    }
    if (!_fin.is_open())
    {
        _fin.open(_file_name.c_str(), std::ios::in);
    }

    return _fin.is_open();
}

bool LocalFsReader::read_line(std::string& result_str)
{
    if (!_fin.is_open())
    {
        return false;
    }
    return std::getline(_fin, result_str);
}
} // namespace code_master
} // namespace inf
} // namespace baidu
