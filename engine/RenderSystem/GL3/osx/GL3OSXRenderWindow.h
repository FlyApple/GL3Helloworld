#ifndef __MXE_GL3OSXRenderWindow_H__
#define __MXE_GL3OSXRenderWindow_H__

#pragma once


#include "GL3RenderWindow.h"

//
class GL3OSXRenderWindow	: public GL3RenderWindow
{
public:
	GL3OSXRenderWindow(void);
	virtual ~GL3OSXRenderWindow(void);

	//
	CGLPixelFormatObj	getCGLPixelFormatObj() { return this->m_pPixelFormatObj; }
	CGLContextObj		getCGLContextObj() { return this->m_pContextObj; }
	
	//
	virtual BOOL	LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values);
	virtual	BOOL	DestroyRenderWindow();

	//
	virtual VOID	Resize(float width, float height);
	
protected:
	virtual BOOL	InitializeOpenGL();
	virtual VOID	ReleaseOpenGL();

	virtual	BOOL	onRenderBegin(RenderSystem* pRenderSystem);
	virtual BOOL	onRenderEnd(RenderSystem* pRenderSystem);
	
protected:
	
	//
	CGLPixelFormatObj	m_pPixelFormatObj;
	CGLContextObj		m_pContextObj;
};


//
#endif //__MXE_GL3OSXRenderWindow_H__