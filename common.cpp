/**
 * common.cpp
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-04 18:16:00
 * Brief: Define common functions.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */

#include <string>
#include <vector>

namespace baidu {
namespace inf {
namespace code_master {
void str_split(const std::string& str, const std::string& delima, std::vector<std::string>& vec)
{
    size_t split_start_idx = 0;
    size_t comma_idx = str.find_first_of(delima);
    while (comma_idx != std::string::npos)
    {
        vec.push_back(str.substr(split_start_idx, comma_idx - split_start_idx));
        split_start_idx = comma_idx + 1;
        comma_idx = str.find_first_of(delima, split_start_idx);
    }
    if (split_start_idx < str.size())
    {
        vec.push_back(str.substr(split_start_idx, str.size() - split_start_idx));
    }
}

} // namespace code_master
} // namespace inf
} // namespace baidu
