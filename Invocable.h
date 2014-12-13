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
        Invocable();
		virtual ~Invocable(){}
		vector<string> GetInvocableList();
		std::string Invoke( string name, vector<string> args );
	private:
		FunctionInvocationMap fmap;
	};
}
