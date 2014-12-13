#include <string>
#include <sstream>

using namespace std;

template < typename T >
T fromString( string const& str )
{
	stringstream ss;
	ss << str;
	T t;
	ss >> t;
	return t;
}

template < typename T >
string toString( T t )
{
	stringstream ss;
	ss.precision(15);
	ss << t;
	return ss.str();
}

