#ifndef __CONTENT_TYPE_H__
#define __CONTENT_TYPE_H__

#include "ContentTypeWriter.h"

class ContentType
{
public:

	virtual ~ContentType() {}

	// Return a content type writer
	virtual ContentTypeWriter* Writer() = 0;
};

#endif
