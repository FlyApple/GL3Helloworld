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
