#ifndef __STREAM_READER_H__
#define __STREAM_READER_H__

class StreamReader
{
public:
	
	virtual ~StreamReader() {}

	// Return if the stream is ready
	virtual bool Ready() = 0;

	// Return the stream size
	virtual unsigned int Size() = 0;

	// Read bytes. Return 0 for EOF, < 0 for errors
	virtual int Read(void* buf, unsigned int size) = 0;
};

#endif
