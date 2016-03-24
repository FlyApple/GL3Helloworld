#ifndef __MXE_RenderWindow_WIN_H__
#define __MXE_RenderWindow_WIN_H__

#pragma once

//
#include "CoreBase.h"
#include "RenderWindow.h"

//
class RenderWindow_WIN	: public RenderWindow
{
public:
	RenderWindow_WIN(void);
	virtual ~RenderWindow_WIN(void);

public:
	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

protected:
	HWND			m_hWnd;
};


//
#endif //__MXE_RenderWindow_WIN_H__