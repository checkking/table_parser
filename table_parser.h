/**
 * table_parser.h
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-05 12:51:00
 * Brief: Declare Table Parser class.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */
#ifndef INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_HELPER_H
#define INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_HELPER_H

#include <string>
#include <vector>

#include "fs_reader.h"
#include "common.h"
#include "parse_helper.h"

namespace baidu {
namespace inf {
namespace code_master {
class TableParser {
public:
    TableParser() {}
    ~TableParser() {}
    bool parse_line(FsReader* fs_reader, const std::string& delima);
    template<typename T>
    Status get_value(const size_t idx, T& result_value);
    template<typename T>
    Status get_vector_value(const size_t idx, std::vector<T>& vector_value);
    const std::vector<std::string>& get_column_strs();

protected:
    std::vector<std::string> column_strs;

private:
    DISALLOW_COPY_AND_ASSIGN(TableParser);
};

template<typename T>
Status TableParser::get_value(const size_t idx, T& result_value)
{
    if (idx >= column_strs.size())
    {
        return OUT_OF_INDEX_ERROR;
    }
    return parse<T>(column_strs.at(idx), result_value);
}

template<typename T>
Status TableParser::get_vector_value(const size_t idx, std::vector<T>& vector_value)
{
    if (idx >= column_strs.size())
    {
        return OUT_OF_INDEX_ERROR;
    }
    return parse_to_vector<T>(column_strs.at(idx), vector_value);
}

} // namespace code_master
} // namespace inf
} // namespace baidu
#endif // INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_HELPER_H
