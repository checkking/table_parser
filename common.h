/**
 * common.h
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-04 18:10:00
 * Brief: Declare comon macros, common Type define, common functions.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */
#ifndef INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_COMMON_H
#define INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_COMMON_H

#include <string>
#include <vector>

namespace baidu {
namespace inf {
namespace code_master {

#define DISALLOW_COPY_AND_ASSIGN(ClassName) \
    ClassName(const ClassName&);    \
    ClassName& operator=(const ClassName&)

enum Status {
    OUT_OF_INDEX_ERROR = -4,
    COLUMN_VECTOR_ERROR = -3,
    COLUMN_EMPTY_ERROR = -2,
    LINE_FORMAT_ERROR = -1,
    SUCCESS = 0
};
typedef enum Status Status;

void str_split(const std::string& str, const std::string& delima, std::vector<std::string>& vec);
} // namespace code_master
} // namespace inf
} // namespace baidu
#endif // INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_COMMON_H
