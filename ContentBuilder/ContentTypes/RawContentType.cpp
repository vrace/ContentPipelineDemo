#include "RawContentType.h"
#include "RawContentWriter.h"

ContentTypeWriter* RawContentType::Writer()
{
	return new RawContentWriter(this);
}

RawContentType::BufferType& RawContentType::GetBuffer()
{
	return _buffer;
}
