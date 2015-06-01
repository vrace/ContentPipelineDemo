#ifndef __ZIP_STREAM_READER_H__
#define __ZIP_STREAM_READER_H__

#include "../zlib/unzip.h"
#include "StreamReader.h"

class ZipStreamReader : public StreamReader
{
public:

	ZipStreamReader(unzFile unz, const char* asset);
	virtual ~ZipStreamReader();

	virtual unsigned int Size();
	virtual int Read(void* buf, unsigned int size);

	virtual bool Ready();

private:

	int _size;
	unzFile _unz;
};

#endif
