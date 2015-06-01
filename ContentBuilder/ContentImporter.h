#ifndef __CONTENT_IMPORTER_H__
#define __CONTENT_IMPORTER_H__

#include "Intermediate.h"

class ContentImporter
{
public:

	virtual ~ContentImporter();

	// Return the importer name
	static const char* Name();

	// Return the imported object
	virtual Intermediate* Import(const char* file) = 0;
};

ContentImporter* FindImporter(const char* extension, const char* importerName);
ContentImporter* DefaultImporter(void);

#endif
