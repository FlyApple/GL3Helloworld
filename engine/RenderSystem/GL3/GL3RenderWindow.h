#ifndef __MXE_GL3RenderWindow_H__
#define __MXE_GL3RenderWindow_H__

#pragma once


#include "RenderWindow.h"

//
class GL3RenderWindow	: public RenderWindow
{
public:
	GL3RenderWindow(void);
	virtual ~GL3RenderWindow(void);

	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

	virtual BOOL	update();
	virtual VOID	flush();

protected:
	virtual BOOL	InitializeOpenGL() = 0;
	virtual VOID	ReleaseOpenGL() = 0;
	
protected:
	//
	float					m_fX;
	float					m_fY;
	
	//
	int						m_nColorBits;
	int						m_nDepthBits;
	int						m_nStencilBits;
};


//
#endif //__MXE_GL3RenderWindow_H__