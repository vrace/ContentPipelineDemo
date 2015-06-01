#include "ContentManager.h"
#include "ZipStreamReader.h"

#include <vector>

ContentManager::ContentManager(const char* contents)
{
	_internal = NULL;

	unzFile unz = unzOpen(contents);
	if (unz)
		_internal = unz;
}

ContentManager::~ContentManager()
{
	if (_internal)
		unzClose(reinterpret_cast<unzFile>(_internal));
}

bool ContentManager::Loaded() const
{
	return !!_internal;
}

StreamReader* ContentManager::GetStreamReader(const char* asset)
{
	ZipStreamReader* reader = NULL;

	if (_internal)
		reader = new ZipStreamReader(reinterpret_cast<unzFile>(_internal), asset);

	return reader;
}

StreamReader& operator >> (StreamReader& stream, std::string& str)
{
	unsigned int len = 0;
	stream.Read(&len, sizeof(len));
	
	std::vector<char> buf(len + 1, 0);
	stream.Read(&buf[0], len);

	str = &buf[0];

	return stream;
}

