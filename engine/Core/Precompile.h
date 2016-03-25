//
//  Precompile.h
//  
//
//  Created by enos sariel on 15/12/19.
//
//

#ifndef __MXE_Precompile_H__
#define __MXE_Precompile_H__

#pragma once

#define _UNICODE

//
#include "Platform.h"

//
#if defined (_PLATFORM_WINDOW_)
#pragma warning(disable: 4819)
#elif defined (_PLATFORM_MAC_)

#if defined(__OBJC__)
#if !defined(__COREFOUNDATION__) || (__COREFOUNDATION__ == 0)
	#error "'Precompile.h' in objective-c, it must be imported or included in it before: ‘Cocoa/Cocoa.h’."
#endif
#endif

#endif

//
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <string>

#include <ctime>

//
#if defined (_PLATFORM_MAC_)

//
#if !defined(OBJC_BOOL_DEFINED)

#define OBJC_BOOL_DEFINED

#if (TARGET_OS_IPHONE && __LP64__)  ||  TARGET_OS_WATCH
#define OBJC_BOOL_IS_BOOL		1
#define BOOL					bool
#else
#define OBJC_BOOL_IS_CHAR		1
#define BOOL					signed char
#endif

#endif

#define TRUE					1
#define FALSE					0

#elif defined(_PLATFORM_LINUX_)

//
#define BOOL					int
#define TRUE					1
#define FALSE					0

//
#define MXE_API_C				extern "C"
#define MXE_API_CPP

#else	//_PLATFORM_X_ other platform.

//
#define MXE_API_C				extern "C"
#define MXE_API_CPP


#endif

//
#if defined(_PLATFORM_WINDOW_)

#include <tchar.h>

#define MXE_CALLBACK			__stdcall

#else

#include "base/baseT.h"
#include "base/charT.h"
		
#define MXE_CALLBACK

#endif

//
#define MXE_DELETE_POINTER(pointer)	if(pointer){ delete pointer; pointer = NULL; }
#define MXE_DELETE_ARRAY(array)		if(array){ delete [] array; array = NULL; }

//
#define StringA			std::string
#define StringW			std::wstring
#ifdef _UNICODE
#define StringT			StringW
#else
#define StringT			StringA
#endif
#define StringArrayT	std::vector<StringT>

//
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>


// 语言支持
#if defined(_PLATFORM_WINDOW_)
	#define MXE_STREAM_LOCALE_CHS	"chs"
	#define MXE_STREAM_LOCALE_ENG	"eng"

#elif defined(_PLATFORM_MAC_)
	#define MXE_STREAM_LOCALE_CHS	"zh_CN"
	#define MXE_STREAM_LOCALE_ENG	"en_US"

#endif

//
#if defined(_PLATFORM_MAC_) || defined(_PLATFORM_LINUX_)

#include <codecvt>

__inline StringW StringAToStringW(StringA str)
{
	std::wstring_convert<std::codecvt_utf8<WCHAR>> convert;
	StringW result = convert.from_bytes(str);
	return result;
}

__inline StringA StringWToStringA(StringW str)
{
	std::wstring_convert<std::codecvt_utf8<WCHAR>> convert;
	StringA result = convert.to_bytes(str);
	return result;
}

__inline StringT StringAToStringT(StringA str)
{
#ifdef _UNICODE
	return StringAToStringW(str);
#else
	return str;
#endif
}

__inline StringT StringWToStringT(StringW str)
{
#ifdef _UNICODE
	return str;
#else
	return StringWToStringA(str);
#endif
}


#endif

//
typedef std::basic_stringstream<TCHAR>		_stringstream_base;
typedef std::basic_ofstream<TCHAR>			_ofstream_base;

typedef _stringstream_base					stringstreamT;
typedef _ofstream_base						ofstreamT;

// 这部分需要定义到std名空间
namespace std{
	#ifdef _UNICODE
	#define coutT			wcout
	#define cerrT			wcerr
	#define endlT			endl
	#else
	#define coutT			cout
	#define cerrT			cerr
	#define endlT			endl
	#endif
}; //namespace std

//
__inline StringT StringToLower(StringT str)
{
	StringT result = str;
	std::transform(result.begin(), result.end(), result.begin(), tolower);
	return result;
}
__inline StringT StringToUpper(StringT str)
{
	StringT result = str;
	std::transform(result.begin(), result.end(), result.begin(), toupper);
	return result;
}

//
template <typename _Ty>
class StringDictionaryT : public std::map<StringT, _Ty>
{
public:
};

//
#endif /* __MXE_Precompile_H__ */
