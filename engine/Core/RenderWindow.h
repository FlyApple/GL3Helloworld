#ifndef __MXE_RenderWindow_H__
#define __MXE_RenderWindow_H__

#pragma once

//
#include "CoreBase.h"

//
class RenderWindow	: public CoreClass
{
public:
	RenderWindow(void);
	virtual ~RenderWindow(void);

public:
	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

protected:
	float				m_fWidth;
	float				m_fHeight;
};


//
#endif //__MXE_RenderWindow_H__