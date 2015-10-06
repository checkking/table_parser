/**
 * fs_reader.h
 * 
 * Author: Chen Kang (chenkang02@baidu.com)
 * Date: 2015-10-05 13:10:00
 * Brief: Declare fs reader class.
 * Copyright (c) Baidu.com Inc. All Rights Reserved.
 */
#ifndef INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_FS_READER_H
#define INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_FS_READER_H

#include <string>
#include <fstream>
#include "common.h"

namespace baidu {
namespace inf {
namespace code_master {
class FsReader {
public:
    FsReader() {}
    virtual ~FsReader() {}
    virtual bool open() = 0;
    virtual bool read_line(std::string& result_str) = 0;
    virtual void close() = 0;
};

class LocalFsReader : public FsReader {
public:
    LocalFsReader() {}
    LocalFsReader(std::string file_name) {
        this->_file_name = file_name;
    }
    virtual ~LocalFsReader() {
        close();
    }
    virtual bool open();
    virtual bool read_line(std::string& result_str);
    virtual void close() {
        if (this->_fin.is_open())
        {
            this->_fin.close();
        }
    }

protected:
    std::string _file_name;
    std::ifstream _fin;
private:
    DISALLOW_COPY_AND_ASSIGN(LocalFsReader);
};
} // namespace code_master
} // namespace inf
} // namespace baidu
#endif // INF_CODEMASTER_TRUNK_CPLUSPLUS_CHENKANG02_FS_READER_H
