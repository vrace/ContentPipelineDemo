#include "StreamWriter.h"

StreamWriter::~StreamWriter()
{
}

StreamWriter& operator << (StreamWriter& stream, const std::string& str)
{
	unsigned int len = str.length();

	stream.Write(&len, sizeof(len));

	if (!str.empty())
		stream.Write(&str[0], len);

	return stream;
}
