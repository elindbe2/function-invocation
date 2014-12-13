#pragma once

#include "StringUtilities.hpp"
#include <cstring>
#include <type_traits>

// this uses fromString by default but
// you can specialize this template if you
// don't want to interfere with the current
// fromString implementation
template <typename T>
T createFromString( std::string the_string )
{
	return fromString<T>(the_string);
}

template <> inline
char * createFromString(std::string the_string)
{
	char * buf = new char[256];
    strcpy( buf, the_string.c_str() );
	return buf;
}

template<typename T> inline
void delete_or_nop (T )    {/* NOP */}

template<typename T> inline
void delete_or_nop(T* p)  {delete p; p = NULL;}

template<typename T> inline
void delete_or_nop(const T*) {/* NOP */ }

template<> inline
void delete_or_nop(char *p){ delete[] p; p = NULL; }

template <typename T>
struct remove_pconst
{
	typedef T type;
};

template <typename T>
struct remove_pconst< const T* > 
{
	typedef T* type;
};

template <typename T>
struct remove_pconst< const T >
{
	typedef T type;
};

template <typename T>
struct get_param_type
{
    typedef typename remove_pconst<typename std::remove_reference<T>::type>::type type;
};

// for variables created on the stack, this function
// can be a no-op but for pointers we may need
// to call delete, depending on the memory management
template <typename T>
void cleanUp(T var)
{
    delete_or_nop<typename std::remove_pointer<T>::type>(var);
}
