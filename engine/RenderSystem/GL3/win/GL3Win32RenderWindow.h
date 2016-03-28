#ifndef __MXE_GL3Win32RenderWindow_H__
#define __MXE_GL3Win32RenderWindow_H__

#pragma once


#include "GL3RenderWindow.h"

//
class GL3Win32RenderWindow	: public GL3RenderWindow
{
public:
	GL3Win32RenderWindow(void);
	virtual ~GL3Win32RenderWindow(void);

	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

protected:
	virtual BOOL	InitializeOpenGL();
	virtual VOID	ReleaseOpenGL();

	virtual BOOL	update();
	virtual VOID	flush();
	
protected:
	HWND					m_hWnd;

	HDC						m_hDC;
	PIXELFORMATDESCRIPTOR	m_PixelFormatDesc;

	HGLRC					m_hGLRC;
};


//
#endif //__MXE_GL3Win32RenderWindow_H__