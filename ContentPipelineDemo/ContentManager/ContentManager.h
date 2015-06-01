#ifndef __CONTENT_MANAGER_H__
#define __CONTENT_MANAGER_H__

#include "StreamReader.h"

#include <string>

class ContentManager
{
public:

	ContentManager(const char* contents);
	~ContentManager();

	bool Loaded() const;

	template <class T>
	T* Load(const char* asset)
	{
		T* p = NULL;

		StreamReader* reader = GetStreamReader(asset);

		if (reader->Ready())
			p = T::FromStream(&*reader);

		delete reader;

		return p;
	}

private:

	StreamReader* GetStreamReader(const char* asset);

private:

	void* _internal;

};

template <class T>
StreamReader& operator >> (StreamReader& stream, T& x)
{
	stream.Read(&x, sizeof(T));
	return stream;
}

StreamReader& operator >> (StreamReader& stream, std::string& str);

#endif
