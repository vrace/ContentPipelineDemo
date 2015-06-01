#ifndef __RAW_CONTENT_WRITER_H__
#define __RAW_CONTENT_WRITER_H__

#include "../ContentTypeWriter.h"

class RawContentWriter : public ContentTypeWriter
{
public:

	RawContentWriter(class RawContentType* content);

	virtual bool Write(StreamWriter* writer);

private:

	class RawContentType* _content;

};

#endif
