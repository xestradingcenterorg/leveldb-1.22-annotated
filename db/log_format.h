// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// Log format information shared by reader and writer.
// See ../doc/log_format.md for more detail.

#ifndef STORAGE_LEVELDB_DB_LOG_FORMAT_H_
#define STORAGE_LEVELDB_DB_LOG_FORMAT_H_

/**
 * 
 * 可以参考doc/log_fomat.md文件
 */
namespace leveldb {
namespace log {

/**
 * 
 * log日志为连续的32k的block块，每个block由record组成
 */
enum RecordType {
  // Zero is reserved for preallocated files
  kZeroType = 0,

  kFullType = 1,//此record包含整块数据 也就是此块数据只存在于1个record中

  // For fragments
  kFirstType = 2,//此record为第一块record
  kMiddleType = 3,//此record为中间的某块record
  kLastType = 4//此record为最后一块record
};
static const int kMaxRecordType = kLastType;

//一个block就是32K
static const int kBlockSize = 32768;

// Header is checksum (4 bytes), length (2 bytes), type (1 byte).
//一个record的头部大小为7
/*
前4个字节为log内容的CRC值
然后2个字节为log内容长度
然后1个字节为record类型 就是enum RecordType
 */
static const int kHeaderSize = 4 + 2 + 1;

}  // namespace log
}  // namespace leveldb

#endif  // STORAGE_LEVELDB_DB_LOG_FORMAT_H_
