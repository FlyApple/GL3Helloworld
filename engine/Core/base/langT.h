//
//  langT.h
//  locale language
//
//  Created by enos sariel on 16/3/31.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __langT_H__
#define __langT_H__

#pragma once

#define MXE_LOCALE_LANGUAGE		MXE_LOCALE_LANGUAGE_CHS

// 语言支持
#if defined(_PLATFORM_WINDOW_)
#define MXE_LOCALE_LANGUAGE_ENG	"eng"
#define MXE_LOCALE_LANGUAGE_CHS	"chs"
#define MXE_LOCALE_LANGUAGE_CHT	"cht"
#define MXE_LOCALE_LANGUAGE_FRA	"fra"
#define MXE_LOCALE_LANGUAGE_DEU	"deu"
#define MXE_LOCALE_LANGUAGE_JPN	"jpn"
#define MXE_LOCALE_LANGUAGE_KOR	"kor"
#define MXE_LOCALE_LANGUAGE_RUS	"rus"

#elif defined(_PLATFORM_MAC_)
#define MXE_LOCALE_LANGUAGE_ENG	"en_US"
#define MXE_LOCALE_LANGUAGE_CHS	"zh_CN"
#define MXE_LOCALE_LANGUAGE_CHT	"zh_TW"
#define MXE_LOCALE_LANGUAGE_FRA	"fr_FR"
#define MXE_LOCALE_LANGUAGE_DEU	"de_DE"
#define MXE_LOCALE_LANGUAGE_JPN	"ja_JP"
#define MXE_LOCALE_LANGUAGE_KOR	"ko_KR"
#define MXE_LOCALE_LANGUAGE_RUS	"ru_RU"

#endif

//
#endif /* __langT_H__ */
