#pragma once

#include "RepeatDefines.h"
#include <Boost/preprocessor/variadic/size.hpp>
#include "StrategyDefines.h"
#include "DBMgr.h"
#include "StringUtilities.hpp"


// Create my defines used to generate the rest of the code 

#define GET_LOG_ARG(num) ,T##num a##num

void LogParams0( void* klassp, std::string function, std::string args  );

#define SAVE_INVOCATION( NARGS, ... ) Invocation::LogParams##NARGS( this, __FUNCTION__, #__VA_ARGS__, ##__VA_ARGS__ );

// Create my invocation save code
namespace Invocation
{

template <typename T> 
void ArgToSStream( std::ostream& os, std::string name, T arg )
{
	os << name << "=" << toString<T>(arg) <<"\001";
}

template <typename T> 
void ArgToSStream( std::ostream& os, std::string name, T*& arg )
{
	if(arg != NULL)
		os << name << "=" << toString<T*>(arg) <<"\001";
	else
		os << name << "=" << "\001";
}

template <> 
void ArgToSStream<char>( std::ostream& os, std::string name, char*& arg );

template <>	
void ArgToSStream<const char>( std::ostream& os, std::string name, const char*& arg );

template <typename T1> void LogParams1(void* klassp, std::string function, std::string args, T1 a1)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 1 + 1 << "\001";
	ss << function << "=" << 1 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2> void LogParams2(void* klassp, std::string function, std::string args, T1 a1, T2 a2)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 2 + 1 << "\001";
	ss << function << "=" << 2 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3> void LogParams3(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 3 + 1 << "\001";
	ss << function << "=" << 3 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4> void LogParams4(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 4 + 1 << "\001";
	ss << function << "=" << 4 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5> void LogParams5(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 5 + 1 << "\001";
	ss << function << "=" << 5 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> void LogParams6(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 6 + 1 << "\001";
	ss << function << "=" << 6 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> void LogParams7(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 7 + 1 << "\001";
	ss << function << "=" << 7 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> void LogParams8(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 8 + 1 << "\001";
	ss << function << "=" << 8 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> void LogParams9(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 9 + 1 << "\001";
	ss << function << "=" << 9 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> void LogParams10(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 10 + 1 << "\001";
	ss << function << "=" << 10 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11> void LogParams11(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 11 + 1 << "\001";
	ss << function << "=" << 11 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12> void LogParams12(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 12 + 1 << "\001";
	ss << function << "=" << 12 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13> void LogParams13(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 13 + 1 << "\001";
	ss << function << "=" << 13 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14> void LogParams14(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 14 + 1 << "\001";
	ss << function << "=" << 14 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15> void LogParams15(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 15 + 1 << "\001";
	ss << function << "=" << 15 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16> void LogParams16(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 16 + 1 << "\001";
	ss << function << "=" << 16 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17> void LogParams17(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 17 + 1 << "\001";
	ss << function << "=" << 17 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18> void LogParams18(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 18 + 1 << "\001";
	ss << function << "=" << 18 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19> void LogParams19(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 19 + 1 << "\001";
	ss << function << "=" << 19 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20> void LogParams20(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 20 + 1 << "\001";
	ss << function << "=" << 20 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21> void LogParams21(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 21 + 1 << "\001";
	ss << function << "=" << 21 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22> void LogParams22(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 22 + 1 << "\001";
	ss << function << "=" << 22 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23> void LogParams23(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 23 + 1 << "\001";
	ss << function << "=" << 23 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24> void LogParams24(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23, T24 a24)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 24 + 1 << "\001";
	ss << function << "=" << 24 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	ArgToSStream(ss, arg_names[24 - 1], a24);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25> void LogParams25(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23, T24 a24, T25 a25)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 25 + 1 << "\001";
	ss << function << "=" << 25 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	ArgToSStream(ss, arg_names[24 - 1], a24);
	ArgToSStream(ss, arg_names[25 - 1], a25);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26> void LogParams26(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23, T24 a24, T25 a25, T26 a26)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 26 + 1 << "\001";
	ss << function << "=" << 26 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	ArgToSStream(ss, arg_names[24 - 1], a24);
	ArgToSStream(ss, arg_names[25 - 1], a25);
	ArgToSStream(ss, arg_names[26 - 1], a26);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27> void LogParams27(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23, T24 a24, T25 a25, T26 a26, T27 a27)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 27 + 1 << "\001";
	ss << function << "=" << 27 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	ArgToSStream(ss, arg_names[24 - 1], a24);
	ArgToSStream(ss, arg_names[25 - 1], a25);
	ArgToSStream(ss, arg_names[26 - 1], a26);
	ArgToSStream(ss, arg_names[27 - 1], a27);
	Invocation::Log(ss.str().c_str());
}
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, typename T17, typename T18, typename T19, typename T20, typename T21, typename T22, typename T23, typename T24, typename T25, typename T26, typename T27, typename T28> void LogParams28(void* klassp, std::string function, std::string args, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16, T17 a17, T18 a18, T19 a19, T20 a20, T21 a21, T22 a22, T23 a23, T24 a24, T25 a25, T26 a26, T27 a27, T28 a28)
{
	args.erase(std::remove_if(args.begin(), args.end(), isspace), args.end());
	std::vector<std::string> arg_names = StringUtilities::Split(args, ',');
	std::stringstream ss;
	ss << "PRCT_INVOCATION=" << 28 + 1 << "\001";
	ss << function << "=" << 28 << "\001";
	ArgToSStream(ss, arg_names[1 - 1], a1);
	ArgToSStream(ss, arg_names[2 - 1], a2);
	ArgToSStream(ss, arg_names[3 - 1], a3);
	ArgToSStream(ss, arg_names[4 - 1], a4);
	ArgToSStream(ss, arg_names[5 - 1], a5);
	ArgToSStream(ss, arg_names[6 - 1], a6);
	ArgToSStream(ss, arg_names[7 - 1], a7);
	ArgToSStream(ss, arg_names[8 - 1], a8);
	ArgToSStream(ss, arg_names[9 - 1], a9);
	ArgToSStream(ss, arg_names[10 - 1], a10);
	ArgToSStream(ss, arg_names[11 - 1], a11);
	ArgToSStream(ss, arg_names[12 - 1], a12);
	ArgToSStream(ss, arg_names[13 - 1], a13);
	ArgToSStream(ss, arg_names[14 - 1], a14);
	ArgToSStream(ss, arg_names[15 - 1], a15);
	ArgToSStream(ss, arg_names[16 - 1], a16);
	ArgToSStream(ss, arg_names[17 - 1], a17);
	ArgToSStream(ss, arg_names[18 - 1], a18);
	ArgToSStream(ss, arg_names[19 - 1], a19);
	ArgToSStream(ss, arg_names[20 - 1], a20);
	ArgToSStream(ss, arg_names[21 - 1], a21);
	ArgToSStream(ss, arg_names[22 - 1], a22);
	ArgToSStream(ss, arg_names[23 - 1], a23);
	ArgToSStream(ss, arg_names[24 - 1], a24);
	ArgToSStream(ss, arg_names[25 - 1], a25);
	ArgToSStream(ss, arg_names[26 - 1], a26);
	ArgToSStream(ss, arg_names[27 - 1], a27);
	ArgToSStream(ss, arg_names[28 - 1], a28);
	Invocation::Log(ss.str().c_str());
}

static DBMgr sTraderDBMgr;

static Lockable sLockStatic;

void Log(std::string message);

unsigned long ParseTestInstanceID(std::string message);
void CreateProxyFnLogTableIfNotExists(const char* table_name);

void StartUpDB(const char* dbHost, const char* dbName, const char* dbLogin, const char* dbPassword, void* param5);



}