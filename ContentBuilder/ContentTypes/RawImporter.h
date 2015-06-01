#ifndef __RAW_IMPORTER_H__
#define __RAW_IMPORTER_H__

#include "../ContentImporter.h"

class RawImporter : public ContentImporter
{
public:

	static const char* Name();
	virtual Intermediate* Import(const char* file);
};

#endif
