#ifndef __STREAM_WRITER_H__
#define __STREAM_WRITER_H__

#include <string>

class StreamWriter
{
public:

	virtual ~StreamWriter();

	// Write binary data
	virtual bool Write(const void* buf, unsigned int size) = 0;
};

template <class T>
StreamWriter& operator << (StreamWriter& stream, const T& x)
{
	stream.Write(&x, sizeof(T));
	return stream;
}

StreamWriter& operator << (StreamWriter& stream, const std::string& str);

#endif
