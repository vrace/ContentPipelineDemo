#ifndef __CONTENT_PROCESSOR_H__
#define __CONTENT_PROCESSOR_H__

#include "Intermediate.h"
#include "ContentType.h"

class ContentProcessor
{
public:

	virtual ~ContentProcessor();

	// Return the processor name
	static const char* Name();

	// Create content type from imported data
	virtual ContentType* Process(Intermediate* data) = 0;
};

ContentProcessor* FindProcessor(const char* extension, const char* processorName);
ContentProcessor* DefaultProcessor(void);

#endif
