#include "Invocable.h"
#include <assert.h>
#include "TwitchDefines.h"
#include "Environment.h"
#include "SaveInvocation.h"

namespace Invocation
{


Invocable::Invocable( void* thisp, std::string table )
{
	STraderInfo info;
	Environment::GetTraderInfo( info );
	StartUpDB(info.dbHost, info.dbName, info.dbLogin, info.dbPassword, NULL );
	
	// Create the  table if it doesn't exist
	CreateProxyFnLogTableIfNotExists( table.c_str() );
}

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
	LOG_INFO("INVOCATION: %s(%s)", name.c_str(), ss.str().c_str());

	return fip->Invoke( args );
}






}
