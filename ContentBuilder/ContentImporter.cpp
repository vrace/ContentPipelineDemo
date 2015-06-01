#include "ContentImporter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ContentImporter::~ContentImporter()
{
}

const char* ContentImporter::Name()
{
	return "";
}

#define IMPORTER_LIST_BEGIN ContentImporter* FindImporter(const char* extension, const char* importerName) {
#define DECLARE_IMPORTER(ext,imp)\
	if (importerName) { if (strcmp(importerName, imp::Name()) == 0) return new imp(); } \
	else if (strcmp(ext, extension) == 0) return new imp();
#define IMPORTER_LIST_END return NULL; }

#include "ContentTypes/RawImporter.h"

IMPORTER_LIST_BEGIN
	DECLARE_IMPORTER("", RawImporter)
IMPORTER_LIST_END

ContentImporter* DefaultImporter(void)
{
	return new RawImporter();
}
