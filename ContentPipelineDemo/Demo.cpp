#include <stdio.h>
#include <stdlib.h>
#include "ContentManager/ContentManager.h"
#include "ContentManager/RawContent.h"

struct FirstCharContent
{
	char ch;

	static FirstCharContent* FromStream(StreamReader* reader)
	{
		FirstCharContent* c = new FirstCharContent();

		*reader >> c->ch;

		return c;
	}
};

int main(void)
{
	ContentManager content("../ContentBuilder/Content.wxf");

	if (content.Loaded())
	{
		printf("\n---- RAW CONTENT TYPE TEST ----\n");

		RawContent* c = content.Load<RawContent>("Content.xml");
		if (c)
		{
			printf("%s\n", c->buffer);
			delete c;
		}
		else
		{
			printf("Failed to load asset.\n");
		}

		printf("\n---- CUSTOM CONTENT TYPE TEST ----\n");

		FirstCharContent* fc = content.Load<FirstCharContent>("Content.xml");
		if (fc)
		{
			printf("First char = %c\n", fc->ch);
			delete fc;
		}
		else
		{
			printf("Failed to load asset.\n");
		}
	}
	else
	{
		printf("Contents not loaded.\n");
	}

	return 0;
}
