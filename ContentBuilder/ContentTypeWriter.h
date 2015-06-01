#ifndef __CONTENT_TYPE_WRITER_H__
#define __CONTENT_TYPE_WRITER_H__

#include "StreamWriter.h"

class ContentTypeWriter
{
public:

	virtual ~ContentTypeWriter() {}

	// Write the data
	virtual bool Write(StreamWriter* writer) = 0;
};

#endif
