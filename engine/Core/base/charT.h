//
//  charT.h
//
//
//  Created by enos sariel on 16/3/25.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

//支持c++ 11规定类型,以4.7.0为基准版本
//特定类型为char16_t用来对应windows 宽字符
//wchar_t 在windows 是 UCS-2BE (UTF-16LE,UNICODE) 2字节
//wchar_t 在unix , linux 是 UTF-32BE 4字节
//由于没有基本的对应库支持，重新实现一系列函数太过费时，故优先考虑4字节


#ifndef __charT_H__
#define __charT_H__

#pragma once

//
#ifdef _UNICODE

#define _WIDE_CHARACTERS

#if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 7 && __GNUC_PATCHLEVEL__ >= 0)
#define __U2(x)					u ## x
#define __U4(x)					U ## x
#else //小于c11版本将全部按4字节处理
#define __U2(x)					L ## x
#define __U4(x)					L ## x
#endif

//支持不全面，暂时用L来统一处理
#define __T(x)					__U4(x)

#else

#define __T(x)					x

#endif

//
#define _T(x)					__T(x)
#define _TEXT(x)				__T(x)

//
#ifdef _UNICODE

#if (__GNUC__ >= 4 && __GNUC_MINOR__ >= 7 && __GNUC_PATCHLEVEL__ >= 0)
typedef char16_t				CHAR16;
typedef char32_t				CHAR32;
#else
typedef wchar_t					CHAR16;
typedef wchar_t					CHAR32;
#endif

typedef CHAR32					WCHAR;

#define TCHAR					WCHAR

#else

typedef char					CHAR;

#define TCHAR					char

#endif

//
#ifdef _WIDE_CHARACTERS

#define _tcslen					wcslen

#define _tcscpy					wcscpy
#define _tcsncpy				wcsncpy
#define _tcscat					wcscat
#define _tcsncat				wcsncat

#define _tcscmp					wcscmp
#define _tcsicmp				wcscasecmp
#define _tcsncmp				wcsncmp
#define _tcsnicmp				wcsncasecmp

#define _tcschr					wcschr
#define _stprinf				swprintf
#define _stscanf				swscanf

#else

#define _tcslen					strlen

#define _tcscpy					strcpy
#define _tcsncpy				strncpy
#define _tcscat					strcat
#define _tcsncat				strncat

#define _tcscmp					strcmp
#define _tcsicmp				strcasecmp
#define _tcsncmp				strncmp
#define _tcsnicmp				strncasecmp

#define _tcschr					strchr
#define _stprinf				sprintf
#define _stscanf				sscanf

#endif

//
#endif /* __charT_H */
