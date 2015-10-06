/**
 * parse_helper.cpp
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-04 18:10:00
 * Brief: Define parse function, including template functions.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */

#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#include "parse_helper.h"

namespace baidu {
namespace inf {
namespace code_master {

Status check_not_empty(const std::string& str)
{
    if ("" == str)
    {
        return COLUMN_EMPTY_ERROR;
    }

    return SUCCESS;
}

template<>
Status parse(const std::string& str, int& result)
{
    if (COLUMN_EMPTY_ERROR == check_not_empty(str)) {
        return COLUMN_EMPTY_ERROR;
    }
    result = atoi(str.c_str());

    return SUCCESS;
}

template<>
Status parse(const std::string& str, float& result) {
    if (COLUMN_EMPTY_ERROR == check_not_empty(str)) {
        return COLUMN_EMPTY_ERROR;
    }

    result = atof(str.c_str());

    return SUCCESS;
}

template<>
Status parse(const std::string& str, std::string& result)
{
    if (COLUMN_EMPTY_ERROR == check_not_empty(str)) {
        return COLUMN_EMPTY_ERROR;
    }

    result = str;
    return SUCCESS;
}


Status check_right_vector(const std::string& str, std::vector<std::string>& vec)
{
    if (SUCCESS != check_not_empty(str)) {
        return COLUMN_VECTOR_ERROR;
    }

    size_t colon_idx = str.find_first_of(':');
    if (colon_idx == std::string::npos) {
        return COLUMN_VECTOR_ERROR;
    }
    int num = atoi(str.substr(0, colon_idx).c_str());
    if (num < 0) 
    {
        return COLUMN_VECTOR_ERROR;
    }
    str_split(str.substr(colon_idx + 1), ",", vec);
    if (static_cast<int>(vec.size()) != num)
    {
        return COLUMN_VECTOR_ERROR;
    }

    return SUCCESS;
}

} // namespace code_master
} // namespace inf
} // namespace baidu
