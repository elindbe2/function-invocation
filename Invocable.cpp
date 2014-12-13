#include "Invocable.h"
#include <assert.h>

namespace Invocation
{


Invocable::Invocable()
{
}

void Invocable::AddInvocation( string name, shared_ptr<FunctionInvoker> fni )
{
	assert(fni != NULL);

	try
	{
		fmap[name] = fni;
	}
	catch (...)
	{
		//LOG_ERROR("There was a problem adding the invocation to the map");
		assert(false);
	}
}

vector<string> Invocable::GetInvocableList()
{
	vector<string> ret;

	for( FunctionInvocationMap::iterator it = fmap.begin(); it != fmap.end(); ++it )
	{
		ret.push_back(it->first);
	}

	return ret;
}

std::string Invocable::Invoke( string name, vector<string> args )
{
	shared_ptr<FunctionInvoker> fip = NULL;
	try
	{
		fip = fmap.at( name );
	}
	catch( out_of_range e )
	{
		//LOG_ERROR("Couldn't find function name in the invocation map." );
		assert(false);  // Couldn't find name in the map
		return "";
	}

	// Log the function call
	stringstream ss;
	ss.str("");
	ss.clear();
	for( auto arg : args )
		ss << arg << " ";

	return fip->Invoke( args );
}


}
