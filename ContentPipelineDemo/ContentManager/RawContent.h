#ifndef __RAW_CONTENT_H__
#define __RAW_COTNENT_H__

#include "StreamReader.h"

struct RawContent
{
	unsigned char *buffer;
	unsigned int size;

	RawContent();
	~RawContent();

	static RawContent* FromStream(StreamReader* reader);
};

#endif
