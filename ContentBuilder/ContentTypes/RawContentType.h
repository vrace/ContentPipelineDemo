#ifndef __RAW_CONTENT_TYPE_H__
#define __RAW_COTNENT_TYPE_H__

#include "../ContentType.h"
#include "../Intermediate.h"
#include <vector>

class RawContentType
	: public ContentType
	, public Intermediate
{
public:

	typedef std::vector<unsigned char> BufferType;

	virtual ContentTypeWriter* Writer();

	BufferType& GetBuffer();

private:

	BufferType _buffer;
};

#endif
