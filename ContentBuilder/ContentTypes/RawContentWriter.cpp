#include "RawContentWriter.h"
#include "RawContentType.h"

RawContentWriter::RawContentWriter(RawContentType* content)
	: _content(content)
{
}

bool RawContentWriter::Write(StreamWriter* writer)
{
	bool succ = false;
	RawContentType::BufferType& buffer = _content->GetBuffer();

	if (!buffer.empty())
		succ = writer->Write(&buffer[0], buffer.size());

	return succ;
}
