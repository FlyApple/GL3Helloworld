//
//  Precompile.h
//  GLTest
//
//  Created by enos sariel on 15/12/19.
//
//

#ifndef __MXE_Precompile_H__
#define __MXE_Precompile_H__

#pragma once

//
#include "Platform.h"

//
#if defined (_PLATFORM_WINDOW_)
#pragma warning(disable: 4819)
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
#define BOOL					int
#define TRUE					1
#define FALSE					0

//
#define MXE_API_C				extern "C"
#define MXE_API_CPP

#else

//
#define MXE_API_C				extern "C"
#define MXE_API_CPP


#endif

//
#if defined(_PLATFORM_WINDOW_)

#include <tchar.h>

#define MXE_CALLBACK			__stdcall

#else

#define __T(x)					L ## x
#define _T(x)					__T(x)
#define _TEXT(x)				__T(x)
		
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


// ����֧��
#if defined(_PLATFORM_WINDOW_)
	#define MXE_STREAM_LOCALE_CHS	"chs"
	#define MXE_STREAM_LOCALE_ENG	"eng"
#endif

//
typedef std::basic_stringstream<TCHAR>		_stringstream_base;
typedef std::basic_ofstream<TCHAR>			_ofstream_base;

typedef _stringstream_base					stringstreamT;
typedef _ofstream_base						ofstreamT;

// �ⲿ����Ҫ���嵽std���ռ�
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
