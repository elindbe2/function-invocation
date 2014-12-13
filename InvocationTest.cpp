// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "Invocable.h"

template <> inline
double * createFromString< double * >(std::string s)
{
	double * d = new double;
	*d = fromString<double>(s);
	return d;
}

using namespace std;
using namespace Invocation;

int Add0( )
{
	cout << "0+0=0" << endl;
	return 0;
}

int Add1( int &a )
{
	cout << "0 + " << a << "=" << 0+a << endl;
	return a;
}

int Add2( int a, int b )
{
	cout << a << " + " << b << "=" << a+b << endl;
	return a + b;
}

void Add3( int a, int b, int c )
{
	int temp = Add2(a, b);
	Add2(temp,c);
}

void Add20( int a, int b, int c, int d, int& e, double f, int g, int h, int i, float j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t )
{
	cout << "Add20=" << a + b + c + d + e + f + g + h + i + j + k + l + m + n + o + p + q + r + s + t << endl;
}

class StreamClass
{
public:
	float value1;
	int value2;

	StreamClass()
		:value1(0.0), value2(0)
	{
	}

	StreamClass( float v1, int v2 )
		: value1( v1 ), value2( v2 )
	{
	}

	friend ostream& operator << ( ostream &os, const StreamClass& sc )
	{
		return os << sc.value1 << "," << sc.value2 <<  "\002";
	}

	friend istream& operator >> ( istream &is, StreamClass& sc )
	{
		char c;
		is >> sc.value1;
		is >> c;
		is >> sc.value2;
		is >> c;
		return is;
	}

};



class Klass : public Invocation::Invocable
{
public:
	double mD;

	Klass() : mD(0.0)
	{
		INVOCABLE_METHOD( Klass::Foo, 0 );
		INVOCABLE_METHOD( Klass::Foo1, 1 );
		INVOCABLE_METHOD( Klass::Foo2, 2 );
		INVOCABLE_METHOD( Klass::Foo3, 3 );
		INVOCABLE_METHOD( Klass::Foo20, 20 );
		INVOCABLE_METHOD( Klass::AddStreamClass, 1 );
	}

	int Foo()
	{
		return 12;
	}
	double Foo1( double * d )
	{
		return *d+100;
	}
	bool Foo2( int a, int const &b )
	{
		return true;
	}

	std::string Foo3( int a, int const b, long c )
	{
		return "Hello, World!";
	}

	void Foo20( int a, int b, int c, int d, int& e, double f, int g, int h, int i, float j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t )
	{
		return;
	}

	float AddStreamClass( StreamClass sc )
	{
		cout << sc.value1 << "+" << sc.value2 << endl;	
		return sc.value1 + sc.value2;
	}
};





int main(int argc, char* argv[])
{
	stringstream ss;
	Klass k = Klass();
	k.mD = 1.0;
	StreamClass sc = StreamClass( 123.3, 532 );

	ss << sc;

	vector<string> vs = k.GetInvocableList();
	for( vector<string>::iterator it = vs.begin(); it != vs.end(); ++it )
		cout << *it << ",";
	cout << endl << endl;
	
	try
	{
		vs.clear();
		std::cout << k.Invoke( "Klass::Foo", vs ) << std::endl;

		vs.push_back( "42.05" );
		std::cout << k.Invoke( "Klass::Foo1", vs ) << std::endl;

		vs.clear();
		vs.push_back("12");
		vs.push_back("13");
		std::cout << k.Invoke( "Klass::Foo2", vs ) << std::endl;

		vs.clear();
		vs.push_back("12");
		vs.push_back("13");
		vs.push_back("15");
		std::cout << k.Invoke( "Klass::Foo3", vs ) << std::endl;

		vs.clear();
		vs.push_back(ss.str());
		std::cout << k.Invoke( "Klass::AddStreamClass", vs ) << std::endl;

		vs.clear();
		for( int i = 1; i < 21; ++i )
		{
			ss.clear();
			ss.str("");
			ss << i;
			vs.push_back( ss.str() );
		}
		std::cout << k.Invoke( "Klass::Foo20", vs ) << std::endl;
	}
	catch( std::exception e )
	{
		cout << "ERROR: " << e.what() << endl;
	}


	return 0;
}

