#include "RawProcessor.h"
#include "RawContentType.h"

const char* RawProcessor::Name()
{
	return "RawProcessor";
}

ContentType* RawProcessor::Process(Intermediate* data)
{
	return static_cast<RawContentType*>(data);
}
