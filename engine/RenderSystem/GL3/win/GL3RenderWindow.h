#ifndef __MXE_GL3RenderWindow_H__
#define __MXE_GL3RenderWindow_H__

#pragma once


#include "win/RenderWindow_WIN.h"

//
class GL3RenderWindow	: public RenderWindow_WIN
{
public:
	GL3RenderWindow(void);
	virtual ~GL3RenderWindow(void);

	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

	virtual	BOOL	RenderBegin(RenderSystem* pRenderSystem);
	virtual BOOL	RenderEnd(RenderSystem* pRenderSystem);

protected:
	virtual BOOL	InitializeOpenGL();
	virtual VOID	ReleaseOpenGL();

protected:
	HDC						m_hDC;
	PIXELFORMATDESCRIPTOR	m_PixelFormatDesc;

	HGLRC					m_hGLRC;

	float					m_fX;
	float					m_fY;
};


//
#endif //__MXE_GL3RenderWindow_H__