#ifndef __RAW_PROCESSOR_H__
#define __RAW_PROCESSOR_H__

#include "../ContentProcessor.h"

class RawProcessor : public ContentProcessor
{
public:

	static const char* Name();

	virtual ContentType* Process(Intermediate* data);
};

#endif
