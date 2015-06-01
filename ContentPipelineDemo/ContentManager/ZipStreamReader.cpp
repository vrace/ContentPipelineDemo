#include "ZipStreamReader.h"

ZipStreamReader::ZipStreamReader(unzFile unz, const char* asset)
{
	_unz = NULL;
	_size = 0;

	if (unzLocateFile(unz, asset, 0) == UNZ_OK &&
		unzOpenCurrentFile(unz) == UNZ_OK)
	{
		unz_file_info info;

		if (unzGetCurrentFileInfo(unz, &info, NULL, 0, NULL, 0, NULL, 0) == UNZ_OK)
		{
			_unz = unz;
			_size = info.uncompressed_size;
		}
		else
		{
			unzCloseCurrentFile(unz);
		}
	}
}

ZipStreamReader::~ZipStreamReader()
{
	if (_unz)
		unzCloseCurrentFile(_unz);
}

unsigned int ZipStreamReader::Size()
{
	return _size;
}

int ZipStreamReader::Read(void* buf, unsigned int size)
{
	int read = -1;

	if (_unz)
		read = unzReadCurrentFile(_unz, buf, size);

	return read;
}

bool ZipStreamReader::Ready()
{
	return !!_unz;
}
