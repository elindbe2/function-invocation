#pragma once

#include "FunctionInvoker.h"
#include "MethodInvoker.h"

namespace Invocation
{
	class Invocable
	{
	protected: 
		void AddInvocation( string name, shared_ptr<FunctionInvoker> fni );
	public:
		Invocable( void* thisp, std::string table = "" );
		Invocable();
		virtual ~Invocable(){}
		vector<string> GetInvocableList();
		std::string Invoke( string name, vector<string> args );
		void Log(unsigned long testInstanceID, std::string message);
	private:
		FunctionInvocationMap fmap;
	};
}
