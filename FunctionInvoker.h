#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "InvokerHelperDefines.h"
#include "RepeatDefines.h"

#define INVOCABLE_FUNCTION( fnname, nargs ) AddInvocation( #fnname, new FunctionInvoker##nargs< decltype(fnname) >( fnname ) );

namespace Invocation
{
	using namespace std;

	struct FunctionInvoker
	{
		void* untyped_ret;
		virtual std::string Invoke( vector<string> s ) = 0;
		virtual ~FunctionInvoker(){}
	};
	
	typedef map<string, shared_ptr<FunctionInvoker>> FunctionInvocationMap;

	template<typename F> 
	struct FunctionInvoker0;

	template<typename R > 
	struct FunctionInvoker0<R(*)( )> : public FunctionInvoker0<R( )>
	{};


	template<typename R > 
	struct FunctionInvoker0<R( )>
		: public FunctionInvoker
	{
		typedef R(*tFnPtr)(void);
		R ret;

		tFnPtr fn;

		FunctionInvoker0( tFnPtr f )
			: fn(f)
		{
			untyped_ret = (void*) &ret;
		}

		std::string Invoke( std::vector<string> s )
		{
			if(s.size() != 0)
				throw exception( "FunctionInvoker: Wrong number of parameters!" );
			ret = fn(   );

			std::string ret_str = toString<R>(ret);
			return ret_str;
		}
	};

	template< > 
	struct FunctionInvoker0<void( )>
		: public FunctionInvoker
	{
		typedef void(*tFnPtr)(void);
		function<void( )> fn;

		FunctionInvoker0( tFnPtr f )
			: fn(f)
		{
			untyped_ret = NULL;
		}

		std::string Invoke( std::vector<string> s )
		{
			if(s.size() != 0)
				throw exception( "FunctionInvoker: Wrong number of parameters!" );
			fn(   );
			return "";
		}
	};

template<typename F> struct FunctionInvstd::string ret_str = toString<R>(ret);oker1;
template<typename R , typename T1> struct FunctionInvoker1<R(*)(T1)> : public FunctionInvoker1<R(T1)> {};
template<typename R, typename T1> struct FunctionInvoker1<R(T1)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1);
    R ret;
    tFnPtr fn;
    FunctionInvoker1( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=1) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    ret = fn( t1 );
    cleanUp<T1>(t1);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1> struct FunctionInvoker1<void(T1)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1);
    tFnPtr fn;
    FunctionInvoker1( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=1) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    fn( t1 );
    cleanUp<T1>(t1);
    return "";
}
};
template<typename F> struct FunctionInvoker2;
template<typename R , typename T1, typename T2> struct FunctionInvoker2<R(*)(T1, T2)> : public FunctionInvoker2<R(T1, T2)> {};
template<typename R, typename T1, typename T2> struct FunctionInvoker2<R(T1, T2)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2);
    R ret;
    tFnPtr fn;
    FunctionInvoker2( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=2) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    ret = fn( t1, t2 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2> struct FunctionInvoker2<void(T1, T2)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2);
    tFnPtr fn;
    FunctionInvoker2( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=2) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    fn( t1, t2 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    return "";
}
};
template<typename F> struct FunctionInvoker3;
template<typename R , typename T1, typename T2, typename T3> struct FunctionInvoker3<R(*)(T1, T2, T3)> : public FunctionInvoker3<R(T1, T2, T3)> {};
template<typename R, typename T1, typename T2, typename T3> struct FunctionInvoker3<R(T1, T2, T3)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3);
    R ret;
    tFnPtr fn;
    FunctionInvoker3( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=3) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    ret = fn( t1, t2, t3 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3> struct FunctionInvoker3<void(T1, T2, T3)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3);
    tFnPtr fn;
    FunctionInvoker3( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=3) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    fn( t1, t2, t3 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    return "";
}
};
template<typename F> struct FunctionInvoker4;
template<typename R , typename T1, typename T2, typename T3, typename T4> struct FunctionInvoker4<R(*)(T1, T2, T3, T4)> : public FunctionInvoker4<R(T1, T2, T3, T4)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4> struct FunctionInvoker4<R(T1, T2, T3, T4)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4);
    R ret;
    tFnPtr fn;
    FunctionInvoker4( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=4) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    ret = fn( t1, t2, t3, t4 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4> struct FunctionInvoker4<void(T1, T2, T3, T4)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4);
    tFnPtr fn;
    FunctionInvoker4( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=4) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    fn( t1, t2, t3, t4 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    return "";
}
};
template<typename F> struct FunctionInvoker5;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5> struct FunctionInvoker5<R(*)(T1, T2, T3, T4, T5)> : public FunctionInvoker5<R(T1, T2, T3, T4, T5)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5> struct FunctionInvoker5<R(T1, T2, T3, T4, T5)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5);
    R ret;
    tFnPtr fn;
    FunctionInvoker5( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=5) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    ret = fn( t1, t2, t3, t4, t5 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5> struct FunctionInvoker5<void(T1, T2, T3, T4, T5)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5);
    tFnPtr fn;
    FunctionInvoker5( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=5) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    fn( t1, t2, t3, t4, t5 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    return "";
}
};
template<typename F> struct FunctionInvoker6;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct FunctionInvoker6<R(*)(T1, T2, T3, T4, T5, T6)> : public FunctionInvoker6<R(T1, T2, T3, T4, T5, T6)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct FunctionInvoker6<R(T1, T2, T3, T4, T5, T6)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6);
    R ret;
    tFnPtr fn;
    FunctionInvoker6( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=6) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    ret = fn( t1, t2, t3, t4, t5, t6 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct FunctionInvoker6<void(T1, T2, T3, T4, T5, T6)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6);
    tFnPtr fn;
    FunctionInvoker6( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=6) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    fn( t1, t2, t3, t4, t5, t6 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    return "";
}
};
template<typename F> struct FunctionInvoker7;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> struct FunctionInvoker7<R(*)(T1, T2, T3, T4, T5, T6, T7)> : public FunctionInvoker7<R(T1, T2, T3, T4, T5, T6, T7)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> struct FunctionInvoker7<R(T1, T2, T3, T4, T5, T6, T7)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7);
    R ret;
    tFnPtr fn;
    FunctionInvoker7( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=7) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> struct FunctionInvoker7<void(T1, T2, T3, T4, T5, T6, T7)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7);
    tFnPtr fn;
    FunctionInvoker7( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=7) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    fn( t1, t2, t3, t4, t5, t6, t7 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    return "";
}
};
template<typename F> struct FunctionInvoker8;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> struct FunctionInvoker8<R(*)(T1, T2, T3, T4, T5, T6, T7, T8)> : public FunctionInvoker8<R(T1, T2, T3, T4, T5, T6, T7, T8)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> struct FunctionInvoker8<R(T1, T2, T3, T4, T5, T6, T7, T8)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8);
    R ret;
    tFnPtr fn;
    FunctionInvoker8( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=8) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> struct FunctionInvoker8<void(T1, T2, T3, T4, T5, T6, T7, T8)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8);
    tFnPtr fn;
    FunctionInvoker8( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=8) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    return "";
}
};
template<typename F> struct FunctionInvoker9;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> struct FunctionInvoker9<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9)> : public FunctionInvoker9<R(T1, T2, T3, T4, T5, T6, T7, T8, T9)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> struct FunctionInvoker9<R(T1, T2, T3, T4, T5, T6, T7, T8, T9)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    R ret;
    tFnPtr fn;
    FunctionInvoker9( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=9) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> struct FunctionInvoker9<void(T1, T2, T3, T4, T5, T6, T7, T8, T9)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    tFnPtr fn;
    FunctionInvoker9( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=9) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    return "";
}
};
template<typename F> struct FunctionInvoker10;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> struct FunctionInvoker10<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> : public FunctionInvoker10<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> struct FunctionInvoker10<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    R ret;
    tFnPtr fn;
    FunctionInvoker10( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=10) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> struct FunctionInvoker10<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    tFnPtr fn;
    FunctionInvoker10( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=10) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    return "";
}
};
template<typename F> struct FunctionInvoker11;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> struct FunctionInvoker11<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)> : public FunctionInvoker11<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> struct FunctionInvoker11<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    R ret;
    tFnPtr fn;
    FunctionInvoker11( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=11) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> struct FunctionInvoker11<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    tFnPtr fn;
    FunctionInvoker11( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=11) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    return "";
}
};
template<typename F> struct FunctionInvoker12;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> struct FunctionInvoker12<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)> : public FunctionInvoker12<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> struct FunctionInvoker12<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    R ret;
    tFnPtr fn;
    FunctionInvoker12( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=12) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> struct FunctionInvoker12<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    tFnPtr fn;
    FunctionInvoker12( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=12) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    return "";
}
};
template<typename F> struct FunctionInvoker13;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> struct FunctionInvoker13<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)> : public FunctionInvoker13<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> struct FunctionInvoker13<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    R ret;
    tFnPtr fn;
    FunctionInvoker13( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=13) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> struct FunctionInvoker13<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    tFnPtr fn;
    FunctionInvoker13( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=13) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    return "";
}
};
template<typename F> struct FunctionInvoker14;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> struct FunctionInvoker14<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)> : public FunctionInvoker14<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> struct FunctionInvoker14<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    R ret;
    tFnPtr fn;
    FunctionInvoker14( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=14) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> struct FunctionInvoker14<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    tFnPtr fn;
    FunctionInvoker14( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=14) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    return "";
}
};
template<typename F> struct FunctionInvoker15;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> struct FunctionInvoker15<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)> : public FunctionInvoker15<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> struct FunctionInvoker15<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    R ret;
    tFnPtr fn;
    FunctionInvoker15( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=15) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> struct FunctionInvoker15<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    tFnPtr fn;
    FunctionInvoker15( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=15) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    return "";
}
};
template<typename F> struct FunctionInvoker16;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> struct FunctionInvoker16<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)> : public FunctionInvoker16<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> struct FunctionInvoker16<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    R ret;
    tFnPtr fn;
    FunctionInvoker16( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=16) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> struct FunctionInvoker16<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    tFnPtr fn;
    FunctionInvoker16( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=16) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    return "";
}
};
template<typename F> struct FunctionInvoker17;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> struct FunctionInvoker17<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)> : public FunctionInvoker17<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> struct FunctionInvoker17<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17);
    R ret;
    tFnPtr fn;
    FunctionInvoker17( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=17) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> struct FunctionInvoker17<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17);
    tFnPtr fn;
    FunctionInvoker17( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=17) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    return "";
}
};
template<typename F> struct FunctionInvoker18;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> struct FunctionInvoker18<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)> : public FunctionInvoker18<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> struct FunctionInvoker18<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18);
    R ret;
    tFnPtr fn;
    FunctionInvoker18( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=18) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> struct FunctionInvoker18<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18);
    tFnPtr fn;
    FunctionInvoker18( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=18) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    return "";
}
};
template<typename F> struct FunctionInvoker19;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> struct FunctionInvoker19<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)> : public FunctionInvoker19<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> struct FunctionInvoker19<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19);
    R ret;
    tFnPtr fn;
    FunctionInvoker19( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=19) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> struct FunctionInvoker19<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19);
    tFnPtr fn;
    FunctionInvoker19( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=19) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    return "";
}
};
template<typename F> struct FunctionInvoker20;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> struct FunctionInvoker20<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)> : public FunctionInvoker20<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> struct FunctionInvoker20<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20);
    R ret;
    tFnPtr fn;
    FunctionInvoker20( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=20) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> struct FunctionInvoker20<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20);
    tFnPtr fn;
    FunctionInvoker20( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=20) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    return "";
}
};
template<typename F> struct FunctionInvoker21;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21> struct FunctionInvoker21<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21)> : public FunctionInvoker21<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21> struct FunctionInvoker21<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21);
    R ret;
    tFnPtr fn;
    FunctionInvoker21( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=21) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21> struct FunctionInvoker21<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21);
    tFnPtr fn;
    FunctionInvoker21( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=21) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    return "";
}
};
template<typename F> struct FunctionInvoker22;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22> struct FunctionInvoker22<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22)> : public FunctionInvoker22<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22> struct FunctionInvoker22<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22);
    R ret;
    tFnPtr fn;
    FunctionInvoker22( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=22) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22> struct FunctionInvoker22<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22);
    tFnPtr fn;
    FunctionInvoker22( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=22) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    return "";
}
};
template<typename F> struct FunctionInvoker23;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23> struct FunctionInvoker23<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23)> : public FunctionInvoker23<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23> struct FunctionInvoker23<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23);
    R ret;
    tFnPtr fn;
    FunctionInvoker23( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=23) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23> struct FunctionInvoker23<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23);
    tFnPtr fn;
    FunctionInvoker23( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=23) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    return "";
}
};
template<typename F> struct FunctionInvoker24;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24> struct FunctionInvoker24<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24)> : public FunctionInvoker24<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24> struct FunctionInvoker24<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24);
    R ret;
    tFnPtr fn;
    FunctionInvoker24( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=24) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24> struct FunctionInvoker24<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24);
    tFnPtr fn;
    FunctionInvoker24( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=24) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    return "";
}
};
template<typename F> struct FunctionInvoker25;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25> struct FunctionInvoker25<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25)> : public FunctionInvoker25<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25> struct FunctionInvoker25<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25);
    R ret;
    tFnPtr fn;
    FunctionInvoker25( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=25) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25> struct FunctionInvoker25<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25);
    tFnPtr fn;
    FunctionInvoker25( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=25) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    return "";
}
};
template<typename F> struct FunctionInvoker26;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26> struct FunctionInvoker26<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26)> : public FunctionInvoker26<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26> struct FunctionInvoker26<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26);
    R ret;
    tFnPtr fn;
    FunctionInvoker26( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=26) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26> struct FunctionInvoker26<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26);
    tFnPtr fn;
    FunctionInvoker26( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=26) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    return "";
}
};
template<typename F> struct FunctionInvoker27;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27> struct FunctionInvoker27<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27)> : public FunctionInvoker27<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27> struct FunctionInvoker27<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27);
    R ret;
    tFnPtr fn;
    FunctionInvoker27( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=27) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    get_param_type<T27>::type t27 = createFromString<get_param_type<T27>::type>(s[27-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    cleanUp<T27>(t27);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27> struct FunctionInvoker27<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27);
    tFnPtr fn;
    FunctionInvoker27( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=27) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    get_param_type<T27>::type t27 = createFromString<get_param_type<T27>::type>(s[27-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    cleanUp<T27>(t27);
    return "";
}
};
template<typename F> struct FunctionInvoker28;
template<typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28> struct FunctionInvoker28<R(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28)> : public FunctionInvoker28<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28)> {};
template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28> struct FunctionInvoker28<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28)> : public FunctionInvoker
{
    typedef R(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28);
    R ret;
    tFnPtr fn;
    FunctionInvoker28( tFnPtr f ) : fn(f)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=28) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    get_param_type<T27>::type t27 = createFromString<get_param_type<T27>::type>(s[27-1]);
    get_param_type<T28>::type t28 = createFromString<get_param_type<T28>::type>(s[28-1]);
    ret = fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    cleanUp<T27>(t27);
    cleanUp<T28>(t28);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28> struct FunctionInvoker28<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28)> : public FunctionInvoker
{
    typedef void(*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28);
    tFnPtr fn;
    FunctionInvoker28( tFnPtr f ) : fn(f)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=28) throw exception( "FunctionInvoker: Wrong number of parameters!" );
    get_param_type<T1>::type t1 = createFromString<get_param_type<T1>::type>(s[1-1]);
    get_param_type<T2>::type t2 = createFromString<get_param_type<T2>::type>(s[2-1]);
    get_param_type<T3>::type t3 = createFromString<get_param_type<T3>::type>(s[3-1]);
    get_param_type<T4>::type t4 = createFromString<get_param_type<T4>::type>(s[4-1]);
    get_param_type<T5>::type t5 = createFromString<get_param_type<T5>::type>(s[5-1]);
    get_param_type<T6>::type t6 = createFromString<get_param_type<T6>::type>(s[6-1]);
    get_param_type<T7>::type t7 = createFromString<get_param_type<T7>::type>(s[7-1]);
    get_param_type<T8>::type t8 = createFromString<get_param_type<T8>::type>(s[8-1]);
    get_param_type<T9>::type t9 = createFromString<get_param_type<T9>::type>(s[9-1]);
    get_param_type<T10>::type t10 = createFromString<get_param_type<T10>::type>(s[10-1]);
    get_param_type<T11>::type t11 = createFromString<get_param_type<T11>::type>(s[11-1]);
    get_param_type<T12>::type t12 = createFromString<get_param_type<T12>::type>(s[12-1]);
    get_param_type<T13>::type t13 = createFromString<get_param_type<T13>::type>(s[13-1]);
    get_param_type<T14>::type t14 = createFromString<get_param_type<T14>::type>(s[14-1]);
    get_param_type<T15>::type t15 = createFromString<get_param_type<T15>::type>(s[15-1]);
    get_param_type<T16>::type t16 = createFromString<get_param_type<T16>::type>(s[16-1]);
    get_param_type<T17>::type t17 = createFromString<get_param_type<T17>::type>(s[17-1]);
    get_param_type<T18>::type t18 = createFromString<get_param_type<T18>::type>(s[18-1]);
    get_param_type<T19>::type t19 = createFromString<get_param_type<T19>::type>(s[19-1]);
    get_param_type<T20>::type t20 = createFromString<get_param_type<T20>::type>(s[20-1]);
    get_param_type<T21>::type t21 = createFromString<get_param_type<T21>::type>(s[21-1]);
    get_param_type<T22>::type t22 = createFromString<get_param_type<T22>::type>(s[22-1]);
    get_param_type<T23>::type t23 = createFromString<get_param_type<T23>::type>(s[23-1]);
    get_param_type<T24>::type t24 = createFromString<get_param_type<T24>::type>(s[24-1]);
    get_param_type<T25>::type t25 = createFromString<get_param_type<T25>::type>(s[25-1]);
    get_param_type<T26>::type t26 = createFromString<get_param_type<T26>::type>(s[26-1]);
    get_param_type<T27>::type t27 = createFromString<get_param_type<T27>::type>(s[27-1]);
    get_param_type<T28>::type t28 = createFromString<get_param_type<T28>::type>(s[28-1]);
    fn( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    cleanUp<T7>(t7);
    cleanUp<T8>(t8);
    cleanUp<T9>(t9);
    cleanUp<T10>(t10);
    cleanUp<T11>(t11);
    cleanUp<T12>(t12);
    cleanUp<T13>(t13);
    cleanUp<T14>(t14);
    cleanUp<T15>(t15);
    cleanUp<T16>(t16);
    cleanUp<T17>(t17);
    cleanUp<T18>(t18);
    cleanUp<T19>(t19);
    cleanUp<T20>(t20);
    cleanUp<T21>(t21);
    cleanUp<T22>(t22);
    cleanUp<T23>(t23);
    cleanUp<T24>(t24);
    cleanUp<T25>(t25);
    cleanUp<T26>(t26);
    cleanUp<T27>(t27);
    cleanUp<T28>(t28);
    return "";
}
};
}
