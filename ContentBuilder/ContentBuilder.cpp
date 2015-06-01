#include <stdio.h>
#include <stdlib.h>

#include "ContentImporter.h"
#include "ContentProcessor.h"
#include "ZipStreamWriter.h"

#include "tinyxml/tinyxml.h"

#define BUILD_ERR_OK        0
#define BUILD_ERR_DEF       1
#define BUILD_ERR_FORMAT    2
#define BUILD_ERR_CREATE    3
#define BUILD_ERR_ENTRY     4
#define BUILD_ERR_IMPORT    5
#define BUILD_ERR_PROCESS   6
#define BUILD_ERR_WRITE     7
#define BUILD_ERR_FINALIZE  8
#define BUILD_ERR_ARG      -1

const char* FileExtension(const char* file)
{
	static char ext[260];

	ext[0] = '\0';

	const char *p = strrchr(file, '.');
	if (p)
		strcpy(ext, p + 1);

	return ext;
}

int AppendContent(zipFile zip, const char* file, const char* imp, const char *proc)
{
	int err = BUILD_ERR_OK;

	ContentImporter* importer = NULL;
	ContentProcessor* processor = NULL;
	Intermediate* intermediate = NULL;
	ContentType* content = NULL;
	ContentTypeWriter* writer = NULL;
	StreamWriter* stream = NULL;

	do
	{
		importer = FindImporter(FileExtension(file), imp);
		processor = FindProcessor(FileExtension(file), proc);

		if (!importer && !imp)
			importer = DefaultImporter();

		if (!processor && !proc)
			processor = DefaultProcessor();

		if (importer)
			intermediate = importer->Import(file);

		if (!intermediate)
		{
			printf("Error: The file '%s' could not be imported.\n", file);
			err = BUILD_ERR_IMPORT;
			break;
		}
		
		if (processor)
			content = processor->Process(intermediate);

		if (!content)
		{
			printf("Error: The file '%s' could not be processed.\n", file);
			err = BUILD_ERR_PROCESS;
			break;
		}

		intermediate = NULL;

		writer = content->Writer();
		stream = new ZipStreamWriter(zip, file);

		if (!writer || !writer->Write(stream))
		{
			printf("Error: Write processed file '%s' failed.\n", file);
			err = BUILD_ERR_WRITE;
			break;
		}
	}
	while (0);

	if (importer)
		delete importer;
	if (processor)
		delete processor;
	if (intermediate)
		delete intermediate;
	if (content)
		delete content;
	if (writer)
		delete writer;
	if (stream)
		delete stream;

	return err;
}

int Build(const char* def)
{
	int err = 0;

	TiXmlDocument doc;
	if (doc.LoadFile(def))
	{
		TiXmlElement *root = doc.FirstChildElement("Contents");
		if (root)
		{
			const char* output = "Contents.wxf";

			const char *opt = root->Attribute("Output");
			if (opt)
				output = opt;

			zipFile zip = zipOpen(output, 0);
			if (zip)
			{
				TiXmlElement *c = root->FirstChildElement("Content");

				for (; c && !err; c = c->NextSiblingElement("Content"))
				{
					const char* file = c->Attribute("File");
					const char* imp = c->Attribute("Importer");
					const char* proc = c->Attribute("Processor");

					if (file)
					{
						printf("%s\n", file);
						err = AppendContent(zip, file, imp, proc);
					}
					else
					{
						printf("Error: Bad entry. File field not set.\n");
						err = BUILD_ERR_ENTRY;
					}
				}

				printf("\n");

				if (zipClose(zip, NULL) == ZIP_OK)
				{
					if (!err)
						printf("Content file '%s' created.\n", output);
				}
				else
				{
					printf("Finialize content file failed.\n");
					err = BUILD_ERR_FINALIZE;
				}
			}
			else
			{
				printf("Error: Could not create content file '%s'.\n", output);
				err = BUILD_ERR_CREATE;
			}
		}
		else
		{
			printf("Error: No contents defined.\n");
			err = BUILD_ERR_FORMAT;
		}
	}
	else
	{
		printf("Error: Could not open content definition '%s'.\n", def);
		err = BUILD_ERR_DEF;
	}

	return err;
}

int main(int argc, char* argv[])
{
	int code = BUILD_ERR_OK;

	printf("Content Builder\n");
	printf("Copyright (c) 2010, 2011, 2012, 2013 wane. All rights reserved.\n");
	printf("\n");

	if (argc != 2)
	{
		printf("Usage: ContentBuilder <Content Definition File>\n");
		code = BUILD_ERR_ARG;
	}
	else
	{
		code = Build(argv[1]);
	}

	return code;
}
