#ifndef __MXE_RenderWindow_H__
#define __MXE_RenderWindow_H__

#pragma once

//
#include "RenderTarget.h"

//
class RenderWindow	: public RenderTarget
{
public:
	RenderWindow(void);
	virtual ~RenderWindow(void);

public:
	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

	virtual	BOOL	RenderBegin(RenderSystem* pRenderSystem){ return TRUE; };
	virtual BOOL	RenderEnd(RenderSystem* pRenderSystem){ return TRUE; };

protected:
	float				m_fWidth;
	float				m_fHeight;
};


//
#endif //__MXE_RenderWindow_H__