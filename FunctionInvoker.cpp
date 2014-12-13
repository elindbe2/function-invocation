#include "FunctionInvoker.h"

namespace Invocation
{

StringInvokable::StringInvokable( )
{
}

void StringInvokable::AddInvocation( string name, shared_ptr<FunctionInvoker> fni )
{
	if(fni == NULL)
		throw exception( "StringInvokable:  You not allowed to use NULL pointer for FunctionInvoker*" );
	try
	{
		fmap[name] = fni;
	}
	catch (...)
	{
		throw exception("There was a problem adding the FunctionInvoker* to the map.");
	}
}

vector<string> StringInvokable::GetInvokableList()
{
	vector<string> ret;

	for( FunctionInvocationMap::iterator it = fmap.begin(); it != fmap.end(); ++it )
	{
		ret.push_back(it->first);
	}

	return ret;
}

void* StringInvokable::Invoke( string name, vector<string> args )
{
	shared_ptr<FunctionInvoker> fip = NULL;
	try
	{
		fip = fmap.at( name );
	}
	catch( out_of_range e )
	{
		throw exception( "Couldn't find function in the invocation map!" );
	}

	// Log the function call
#ifdef _DEBUG
	stringstream ss;
	ss.str("");
	ss.clear();
	vector<string>::iterator it = args.begin();
	ss << *it++; 
	while(it != args.end() )
		ss << "," << *it++;
	Log(NULL, INFO, "Strategy Proxy Call: %s(%s)", name.c_str(), ss.str().c_str());
#endif

	fip->Invoke( args );
	return fip->untyped_ret;
}

}