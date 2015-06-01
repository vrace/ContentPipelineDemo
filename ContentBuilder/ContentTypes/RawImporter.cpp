#include "RawImporter.h"
#include "RawContentType.h"

#include <stdio.h>
#include <stdlib.h>

const char* RawImporter::Name()
{
	return "RawImporter";
}

Intermediate* RawImporter::Import(const char* file)
{
	FILE* fp;
	RawContentType* content = NULL;

	fp = fopen(file, "rb");
	if (fp)
	{
		long size;

		fseek(fp, 0, SEEK_END);
		size = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		content = new RawContentType();

		RawContentType::BufferType& buffer = content->GetBuffer();

		buffer.resize(size);
		
		if (size > 0)
			fread(&buffer[0], 1, size, fp);

		fclose(fp);
	}

	return content;
}
