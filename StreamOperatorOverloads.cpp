#include "Invocation/StreamOperatorOverloads.h"
#include <sstream>

// Stream operator overloads
template <>
unsigned long GetFromString( const char* s )
{
	return atol(s);
}

template <>
int GetFromString( const char* s )
{
	return atoi(s);
}

template <>
double GetFromString( const char* s )
{
	return atof(s);
}

template <>
string GetFromString( const char* s )
{
	return string(s);
}

template <>
__int64 GetFromString( const char* s)
{
	__int64 val;
	sscanf(s, "%I64d", &val);
	return val;
}

istream& operator>>(istream& is, double*& d)
{
	return is;
}	

std::stringstream& operator>>(std::stringstream& ss , char* a)	// this overload reads the whitespace characters too from the stream!
{
	char c;
	while (true)
	{
		c = ss.get();
		if(!ss.eof())
		{
			*a = c;
			++a;
		}
		else
		{
			*a = '\0';
			break;
		}
	}

	return ss;
}

stringstream& operator>>(stringstream& ss , string& a)
{
	char c;
	while (true)
	{
		c = ss.get();
		if(!ss.eof())
		{
			a.push_back(c);
		}
		else
		{
			break;
		}
	}

	return ss;
}
