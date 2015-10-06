/**
 * parser_helper.h
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-04 18:10:00
 * Brief: Declare parse function, including template functions.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */
#ifndef INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_PARSE_HELPER_H
#define INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_PARSE_HELPER_H

#include <string>
#include <vector>

#include "common.h"

namespace baidu {
namespace inf {
namespace code_master {
template<typename T>
Status parse(const std::string& str, T& result);
template<>
Status parse(const std::string& str, int& result);
template<>
Status parse(const std::string& str, float& result);
template<>
Status parse(const std::string& str, std::string& result);

template<typename T>
Status parse_to_vector(const std::string& str, std::vector<T>& result);

Status check_not_empty(const std::string& str);

Status check_right_vector(const std::string& str, std::vector<std::string>& vec);

template<typename T>
Status parse_to_vector(const std::string& str, std::vector<T>& result)
{
    std::vector<std::string> vec;
    if (COLUMN_VECTOR_ERROR == check_right_vector(str, vec))
    {
        return COLUMN_VECTOR_ERROR;
    }
    for (std::vector<std::string>::iterator itr = vec.begin(); itr != vec.end(); itr++)
    {
        T parse_result;
        Status status = parse<T>(*itr, parse_result);
        if (status != SUCCESS)
        {
            result.clear();
            return status;
        }
        result.push_back(parse_result);
    }

    return SUCCESS;
}

} // namespace code_master
} // namespace inf
} // namespace baidu
#endif // INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_PARSE_HELPER_H
