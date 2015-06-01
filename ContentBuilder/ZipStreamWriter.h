#ifndef __ZIP_STREAM_WRITER_H__
#define __ZIP_STREAM_WRITER_H__

#include "StreamWriter.h"
#include "zlib/zip.h"

class ZipStreamWriter : public StreamWriter
{
public:

	ZipStreamWriter(zipFile zip, const char* file);
	virtual ~ZipStreamWriter();

	virtual bool Write(const void* buf, unsigned int size);

private:

	zipFile _zip;
};

#endif
