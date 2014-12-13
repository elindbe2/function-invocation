#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "InvokerHelperDefines.h"
#include "FunctionInvoker.h"

#define INVOCABLE_METHOD( methodname, nargs ) AddInvocation( #methodname, make_shared<Invocation::MethodInvoker##nargs<decltype(&methodname)>>(*this, &methodname));

namespace Invocation
{
using namespace std;

template<typename F> 
struct MethodInvoker0;


template<typename K, typename R > 
struct MethodInvoker0<R(K::*)( void )> : public FunctionInvoker
{
	typedef R(K::*tFnPtr)(void);

    R ret;
	tFnPtr fn;	

	K* kp;

	MethodInvoker0( K& k,  tFnPtr f )
		: fn(f), kp( &k )
	{
		untyped_ret = (void*) &ret;
	}

	std::string Invoke( vector<string> s )
	{
		if(s.size() != 0)
            throw wrong_number_of_parameters();
		ret = ((*kp).*fn)();

		std::string ret_str("");
		{
			std::stringstream ss;
			ss << ret;
			ret_str = ss.str();
		}
		return ret_str;
	}
};

template< typename K > 
struct MethodInvoker0<void(K::*)( void )> : public FunctionInvoker
{
	typedef void(K::*tFnPtr)(void);

	tFnPtr fn;	
	K* kp;

	MethodInvoker0( K& k,  tFnPtr f )
		: fn(f), kp( &k )
	{
		untyped_ret = NULL;
	}

	std::string Invoke( vector<string> s )
	{
		if(s.size() != 0)
            throw wrong_number_of_parameters();
		((*kp).*fn)();

		return "";
	}
};


// Define method invokers for up to 30 arguments
template<typename F> struct MethodInvoker1;
template<typename K, typename R , typename T1> struct MethodInvoker1<R(K::*)(T1)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker1( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=1) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    ret = ((*kp).*fn)( t1 );
    cleanUp<T1>(t1);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template< typename K, typename T1 > struct MethodInvoker1<void(K::*)( T1 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1);
    tFnPtr fn;
    K* kp;
    MethodInvoker1( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=1) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    ((*kp).*fn)( t1 );
    cleanUp<T1>(t1);
    return "";
}
};
template<typename F> struct MethodInvoker2;
template<typename K, typename R , typename T1, typename T2> struct MethodInvoker2<R(K::*)(T1, T2)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker2( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=2) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    ret = ((*kp).*fn)( t1, t2 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template< typename K, typename T1, typename T2 > struct MethodInvoker2<void(K::*)( T1, T2 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2);
    tFnPtr fn;
    K* kp;
    MethodInvoker2( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=2) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    ((*kp).*fn)( t1, t2 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    return "";
}
};
template<typename F> struct MethodInvoker3;
template<typename K, typename R , typename T1, typename T2, typename T3> struct MethodInvoker3<R(K::*)(T1, T2, T3)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker3( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=3) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    ret = ((*kp).*fn)( t1, t2, t3 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template< typename K, typename T1, typename T2, typename T3 > struct MethodInvoker3<void(K::*)( T1, T2, T3 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3);
    tFnPtr fn;
    K* kp;
    MethodInvoker3( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=3) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    ((*kp).*fn)( t1, t2, t3 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    return "";
}
};
template<typename F> struct MethodInvoker4;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4> struct MethodInvoker4<R(K::*)(T1, T2, T3, T4)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker4( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=4) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template< typename K, typename T1, typename T2, typename T3, typename T4 > struct MethodInvoker4<void(K::*)( T1, T2, T3, T4 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4);
    tFnPtr fn;
    K* kp;
    MethodInvoker4( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=4) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    ((*kp).*fn)( t1, t2, t3, t4 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    return "";
}
};
template<typename F> struct MethodInvoker5;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5> struct MethodInvoker5<R(K::*)(T1, T2, T3, T4, T5)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker5( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=5) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    std::string ret_str = toString<R>(ret);
    return ret_str;
}
};
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5 > struct MethodInvoker5<void(K::*)( T1, T2, T3, T4, T5 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5);
    tFnPtr fn;
    K* kp;
    MethodInvoker5( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=5) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    return "";
}
};
template<typename F> struct MethodInvoker6;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct MethodInvoker6<R(K::*)(T1, T2, T3, T4, T5, T6)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker6( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=6) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 > struct MethodInvoker6<void(K::*)( T1, T2, T3, T4, T5, T6 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6);
    tFnPtr fn;
    K* kp;
    MethodInvoker6( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=6) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6 );
    cleanUp<T1>(t1);
    cleanUp<T2>(t2);
    cleanUp<T3>(t3);
    cleanUp<T4>(t4);
    cleanUp<T5>(t5);
    cleanUp<T6>(t6);
    return "";
}
};
template<typename F> struct MethodInvoker7;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> struct MethodInvoker7<R(K::*)(T1, T2, T3, T4, T5, T6, T7)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker7( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=7) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7 > struct MethodInvoker7<void(K::*)( T1, T2, T3, T4, T5, T6, T7 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7);
    tFnPtr fn;
    K* kp;
    MethodInvoker7( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=7) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7 );
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
template<typename F> struct MethodInvoker8;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> struct MethodInvoker8<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker8( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=8) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 > struct MethodInvoker8<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8);
    tFnPtr fn;
    K* kp;
    MethodInvoker8( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=8) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8 );
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
template<typename F> struct MethodInvoker9;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> struct MethodInvoker9<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker9( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=9) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 > struct MethodInvoker9<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
    tFnPtr fn;
    K* kp;
    MethodInvoker9( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=9) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9 );
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
template<typename F> struct MethodInvoker10;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> struct MethodInvoker10<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker10( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=10) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10 > struct MethodInvoker10<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
    tFnPtr fn;
    K* kp;
    MethodInvoker10( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=10) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 );
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
template<typename F> struct MethodInvoker11;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> struct MethodInvoker11<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker11( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=11) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11 > struct MethodInvoker11<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
    tFnPtr fn;
    K* kp;
    MethodInvoker11( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=11) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11 );
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
template<typename F> struct MethodInvoker12;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> struct MethodInvoker12<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker12( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=12) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12 > struct MethodInvoker12<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
    tFnPtr fn;
    K* kp;
    MethodInvoker12( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=12) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12 );
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
template<typename F> struct MethodInvoker13;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> struct MethodInvoker13<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker13( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=13) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13 > struct MethodInvoker13<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
    tFnPtr fn;
    K* kp;
    MethodInvoker13( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=13) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13 );
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
template<typename F> struct MethodInvoker14;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> struct MethodInvoker14<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker14( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=14) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14 > struct MethodInvoker14<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
    tFnPtr fn;
    K* kp;
    MethodInvoker14( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=14) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14 );
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
template<typename F> struct MethodInvoker15;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> struct MethodInvoker15<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker15( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=15) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15 > struct MethodInvoker15<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
    tFnPtr fn;
    K* kp;
    MethodInvoker15( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=15) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15 );
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
template<typename F> struct MethodInvoker16;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> struct MethodInvoker16<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker16( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=16) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16 > struct MethodInvoker16<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
    tFnPtr fn;
    K* kp;
    MethodInvoker16( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=16) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16 );
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
template<typename F> struct MethodInvoker17;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> struct MethodInvoker17<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker17( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=17) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17 > struct MethodInvoker17<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17);
    tFnPtr fn;
    K* kp;
    MethodInvoker17( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=17) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17 );
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
template<typename F> struct MethodInvoker18;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> struct MethodInvoker18<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker18( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=18) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18 > struct MethodInvoker18<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18);
    tFnPtr fn;
    K* kp;
    MethodInvoker18( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=18) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18 );
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
template<typename F> struct MethodInvoker19;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> struct MethodInvoker19<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker19( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=19) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19 > struct MethodInvoker19<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19);
    tFnPtr fn;
    K* kp;
    MethodInvoker19( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=19) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19 );
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
template<typename F> struct MethodInvoker20;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> struct MethodInvoker20<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker20( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=20) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20 > struct MethodInvoker20<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20);
    tFnPtr fn;
    K* kp;
    MethodInvoker20( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=20) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20 );
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
template<typename F> struct MethodInvoker21;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21> struct MethodInvoker21<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker21( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=21) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21 > struct MethodInvoker21<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21);
    tFnPtr fn;
    K* kp;
    MethodInvoker21( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=21) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21 );
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
template<typename F> struct MethodInvoker22;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22> struct MethodInvoker22<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker22( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=22) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22 > struct MethodInvoker22<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22);
    tFnPtr fn;
    K* kp;
    MethodInvoker22( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=22) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22 );
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
template<typename F> struct MethodInvoker23;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23> struct MethodInvoker23<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker23( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=23) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23 > struct MethodInvoker23<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23);
    tFnPtr fn;
    K* kp;
    MethodInvoker23( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=23) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23 );
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
template<typename F> struct MethodInvoker24;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24> struct MethodInvoker24<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker24( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=24) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24 > struct MethodInvoker24<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24);
    tFnPtr fn;
    K* kp;
    MethodInvoker24( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=24) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24 );
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
template<typename F> struct MethodInvoker25;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25> struct MethodInvoker25<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker25( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=25) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25 > struct MethodInvoker25<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25);
    tFnPtr fn;
    K* kp;
    MethodInvoker25( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=25) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25 );
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
template<typename F> struct MethodInvoker26;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26> struct MethodInvoker26<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker26( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=26) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26 > struct MethodInvoker26<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26);
    tFnPtr fn;
    K* kp;
    MethodInvoker26( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=26) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26 );
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
template<typename F> struct MethodInvoker27;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27> struct MethodInvoker27<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker27( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=27) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    typename get_param_type<T27>::type t27 = createFromString<typename get_param_type<T27>::type>(s[27-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27 > struct MethodInvoker27<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27);
    tFnPtr fn;
    K* kp;
    MethodInvoker27( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=27) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    typename get_param_type<T27>::type t27 = createFromString<typename get_param_type<T27>::type>(s[27-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27 );
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
template<typename F> struct MethodInvoker28;
template<typename K, typename R , typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28> struct MethodInvoker28<R(K::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28)> : public FunctionInvoker
{
    typedef R(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28);
    R ret;
    tFnPtr fn;
    K* kp;
    MethodInvoker28( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = (void*) &ret;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=28) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    typename get_param_type<T27>::type t27 = createFromString<typename get_param_type<T27>::type>(s[27-1]);
    typename get_param_type<T28>::type t28 = createFromString<typename get_param_type<T28>::type>(s[28-1]);
    ret = ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28 );
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
template< typename K, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28 > struct MethodInvoker28<void(K::*)( T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28 )> : public FunctionInvoker
{
    typedef void(K::*tFnPtr)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28);
    tFnPtr fn;
    K* kp;
    MethodInvoker28( K& k, tFnPtr f ) : fn(f), kp(&k)
{
    untyped_ret = 0;
} std::string Invoke( vector<string> s )
{
    if(s.size() !=28) throw wrong_number_of_parameters();
    typename get_param_type<T1>::type t1 = createFromString<typename get_param_type<T1>::type>(s[1-1]);
    typename get_param_type<T2>::type t2 = createFromString<typename get_param_type<T2>::type>(s[2-1]);
    typename get_param_type<T3>::type t3 = createFromString<typename get_param_type<T3>::type>(s[3-1]);
    typename get_param_type<T4>::type t4 = createFromString<typename get_param_type<T4>::type>(s[4-1]);
    typename get_param_type<T5>::type t5 = createFromString<typename get_param_type<T5>::type>(s[5-1]);
    typename get_param_type<T6>::type t6 = createFromString<typename get_param_type<T6>::type>(s[6-1]);
    typename get_param_type<T7>::type t7 = createFromString<typename get_param_type<T7>::type>(s[7-1]);
    typename get_param_type<T8>::type t8 = createFromString<typename get_param_type<T8>::type>(s[8-1]);
    typename get_param_type<T9>::type t9 = createFromString<typename get_param_type<T9>::type>(s[9-1]);
    typename get_param_type<T10>::type t10 = createFromString<typename get_param_type<T10>::type>(s[10-1]);
    typename get_param_type<T11>::type t11 = createFromString<typename get_param_type<T11>::type>(s[11-1]);
    typename get_param_type<T12>::type t12 = createFromString<typename get_param_type<T12>::type>(s[12-1]);
    typename get_param_type<T13>::type t13 = createFromString<typename get_param_type<T13>::type>(s[13-1]);
    typename get_param_type<T14>::type t14 = createFromString<typename get_param_type<T14>::type>(s[14-1]);
    typename get_param_type<T15>::type t15 = createFromString<typename get_param_type<T15>::type>(s[15-1]);
    typename get_param_type<T16>::type t16 = createFromString<typename get_param_type<T16>::type>(s[16-1]);
    typename get_param_type<T17>::type t17 = createFromString<typename get_param_type<T17>::type>(s[17-1]);
    typename get_param_type<T18>::type t18 = createFromString<typename get_param_type<T18>::type>(s[18-1]);
    typename get_param_type<T19>::type t19 = createFromString<typename get_param_type<T19>::type>(s[19-1]);
    typename get_param_type<T20>::type t20 = createFromString<typename get_param_type<T20>::type>(s[20-1]);
    typename get_param_type<T21>::type t21 = createFromString<typename get_param_type<T21>::type>(s[21-1]);
    typename get_param_type<T22>::type t22 = createFromString<typename get_param_type<T22>::type>(s[22-1]);
    typename get_param_type<T23>::type t23 = createFromString<typename get_param_type<T23>::type>(s[23-1]);
    typename get_param_type<T24>::type t24 = createFromString<typename get_param_type<T24>::type>(s[24-1]);
    typename get_param_type<T25>::type t25 = createFromString<typename get_param_type<T25>::type>(s[25-1]);
    typename get_param_type<T26>::type t26 = createFromString<typename get_param_type<T26>::type>(s[26-1]);
    typename get_param_type<T27>::type t27 = createFromString<typename get_param_type<T27>::type>(s[27-1]);
    typename get_param_type<T28>::type t28 = createFromString<typename get_param_type<T28>::type>(s[28-1]);
    ((*kp).*fn)( t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28 );
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
