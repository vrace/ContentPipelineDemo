#include "ZipStreamWriter.h"

ZipStreamWriter::ZipStreamWriter(zipFile zip, const char* file)
{
	_zip = NULL;

	if (zip)
	{
		if (zipOpenNewFileInZip(zip, file, NULL, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_DEFAULT_COMPRESSION) == ZIP_OK)
		{
			_zip = zip;
		}
	}
}

ZipStreamWriter::~ZipStreamWriter()
{
	if (_zip)
	{
		zipCloseFileInZip(_zip);
	}
}

bool ZipStreamWriter::Write(const void* buf, unsigned int size)
{
	bool succ = false;

	if (_zip)
	{
		if (zipWriteInFileInZip(_zip, buf, size) == ZIP_OK)
			succ = true;
	}

	return succ;
}
