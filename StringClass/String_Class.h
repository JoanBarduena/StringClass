#ifndef STRING_H
#define STRING_H
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

class String
{
private:

	unsigned int mem_allocated = 0;
	char* str = nullptr;

	//Constructors
	String(const char* string) 
	{
		if (string != NULL)
		{
			mem_allocated = strlen(string) + 1; 
			str = new char[mem_allocated];
			strcpy(str, string);
		}
	};

	String(const String &copyString)
	{
		mem_allocated = copyString.mem_allocated; 
		str = new char[mem_allocated];
		strcpy(str, copyString.str);
	}; 

	String() {}; 

	//Destructor
	~String() 
	{
		if (str != NULL)
		{
			delete[] str;
			str = nullptr; 
			//mem_allocated = 0; --> not necessary      
		}
	}

public: 

	bool empty() const
	{
		return mem_allocated == 0;
	}

	unsigned int size() const
	{
		return mem_allocated;
	}

	unsigned int length() const
	{
		if (str != NULL) { return strlen(str);  }
	}

	void clear()
	{
		if (str != NULL)
		{
			delete[] str;
			str = nullptr;
			mem_allocated = 0;
		}
	}

	//operator = 
	String operator=(String &str);
};

#endif //STRING_H

String String::operator= (String &string)
{
	delete[] str; 
	if (string.length() != 0)
	{
		mem_allocated = string.length(); 
		str = new char[mem_allocated]; 
		for (int i = 0; i <	mem_allocated; ++i)
		{
			str[i] = string.str[i]; 
		}
		return *this; 
	}
}