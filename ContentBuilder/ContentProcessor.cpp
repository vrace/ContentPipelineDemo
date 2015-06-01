#include "ContentProcessor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ContentProcessor::~ContentProcessor()
{
}

const char* ContentProcessor::Name()
{
	return "";
}

#define BEGIN_PROCESSOR_LIST ContentProcessor* FindProcessor(const char* extension, const char* processorName) {
#define DECLARE_PROCESSOR(ext,proc)\
	if (processorName) { if (strcmp(processorName, proc::Name()) == 0) return new proc(); } \
	else if (strcmp(extension, ext) == 0) return new proc();
#define END_PROCESSOR_LIST return NULL; }

#include "ContentTypes/RawProcessor.h"

BEGIN_PROCESSOR_LIST
	DECLARE_PROCESSOR("", RawProcessor)
END_PROCESSOR_LIST

ContentProcessor* DefaultProcessor(void)
{
	return new RawProcessor();
}
