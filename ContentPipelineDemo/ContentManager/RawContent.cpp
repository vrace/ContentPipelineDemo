#include "RawContent.h"

#include <stdio.h>
#include <stdlib.h>

RawContent::RawContent()
	: size(0)
	, buffer(NULL)
{
}

RawContent::~RawContent()
{
	if (buffer)
		delete[] buffer;
}

RawContent* RawContent::FromStream(StreamReader* reader)
{
	RawContent* c = new RawContent();

	c->size = reader->Size();
	c->buffer = new unsigned char[c->size + 1];

	int read = reader->Read(c->buffer, c->size);
	c->buffer[c->size] = 0;

	if (read != static_cast<int>(c->size))
	{
		delete c;
		c = NULL;
	}

	return c;
}
