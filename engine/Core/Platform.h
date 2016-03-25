//
//  Platform.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//
//

#ifndef __MXE_Platform_H__
#define __MXE_Platform_H__

#pragma once

//
#if defined (__APPLE__)
//#if defined(__GNUC__) && ( defined(__APPLE_CPP__) || defined(__APPLE_CC__) || defined(__MACOS_CLASSIC__) )

#define __OS_APPLE_MAC__

#elif defined (_MSC_VER)

#define __OS_WINDOW__
#ifdef _WIN64
#define __OS_WINDOW_64__
#else
#define __OS_WINDOW_32__
#endif

#elif defined (__GNUC__)

#define __OS_LINUX__

#endif

//-------------- Apple Mac Platform -----------------
#if defined __OS_APPLE_MAC__

#define _PLATFORM_MAC_


#endif //__OS_APPLE_MAC__

//-------------- Window Global Platform -----------------
#if defined __OS_WINDOW__

#define _PLATFORM_WINDOW_

#include <windows.h>

#endif //__OS_WINDOW__

//-------------- Window 32bit Platform -----------------
#if defined __OS_WINDOW_64__

#define _PLATFORM_WIN_X64_


#endif //__OS_WINDOW_64__

//-------------- Window 64bit Platform -----------------
#if defined __OS_WINDOW_32__

#define _PLATFORM_WIN_X32_


#endif //__OS_WINDOW_32__

//-------------- Linux Platform -----------------
#if defined __OS_LINUX__

#define _PLATFORM_LINUX_


#endif //__OS_LINUX__

//
#endif /* __MXE_Platform_H__ */
