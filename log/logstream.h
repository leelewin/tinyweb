#ifndef TINYHTTP_LOG_LOGSTREAM_H
#define TINYHTTP_LOG_LOGSTREAM_H

#include "../util/fixedbuffer.h"
#include <string>

// const int kSmallBuffSize = 4000;
// const int kLargeBuffSize = 4000 * 1000;

//类型安全和类型可扩展，不支持定制格式化，没有动态分配内存
//适合logging以及简单的字符串转换
class LogStream {
public:
	typedef FixedBuffer<kSmallBuffSize> Buffer;
	LogStream();

	LogStream(const LogStream &) = delete;
	LogStream& operator= (const LogStream &) = delete;

	void append(const char* data, int len);
	const Buffer& buffer() const;
	void resetBuffer();

	LogStream& operator<< (bool v);
	LogStream& operator<< (char v);
	LogStream& operator<< (int v);
	LogStream& operator<< (double v);
	LogStream& operator<< (const char* str);
	LogStream& operator<< (const std::string &v);

private:
	Buffer buffer_;
	static const int kMaxNumericSize = 48;  //48?

};

#endif // TINYHTTP_LOG_LOGSTREAM_H