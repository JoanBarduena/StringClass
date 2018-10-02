#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

class String
{
private:

	unsigned int mem_allocated = 0;
	char* str = nullptr;

public:

	//Constructor
	String(const char* string) 
	{
		if (string != NULL)
		{
			mem_allocated = strlen(string) + 1; 
			str = new char[mem_allocated];
			strcpy(str, string);
		}
	};

	String(String &copyString)
	{
		str = new char[copyString.mem_allocated];
		strcpy(str, copyString.str);
	}

	//Destructor
	~String() { delete[] str; }

	bool empty() const
	{
		return mem_allocated == 0;
	}

	unsigned int size() const
	{
		return mem_allocated;
	}

	void clear()
	{
		delete[] str;
		str = nullptr;
		mem_allocated = 0;
	}

};

#endif //STRING_H

