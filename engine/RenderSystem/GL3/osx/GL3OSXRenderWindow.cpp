
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3OSXRenderWindow.h"

#include "LogManager.h"

//
GL3OSXRenderWindow::GL3OSXRenderWindow(void)
{
	this->m_pPixelFormatObj		= NULL;
	this->m_pContextObj			= NULL;
}

GL3OSXRenderWindow::~GL3OSXRenderWindow(void)
{
}

BOOL	GL3OSXRenderWindow::DestroyRenderWindow()
{
	if(!GL3RenderWindow::DestroyRenderWindow())
	{ return FALSE; }
	
	//
	return TRUE;
}

BOOL	GL3OSXRenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!GL3RenderWindow::LoadRenderWindow(option_values)){ return FALSE; }

	//
	if(!InitializeOpenGL())
	{
		return FALSE;
	}

	return TRUE;
}

VOID	GL3OSXRenderWindow::ReleaseOpenGL()
{
	if(m_pContextObj)
	{
		CGLContextObj	pContextObj = CGLGetCurrentContext();
		if(pContextObj == m_pContextObj)
		{
			CGLSetCurrentContext(NULL);
		}
		
		CGLReleaseContext(m_pContextObj);
		m_pContextObj = NULL;
	}
	
	if(m_pPixelFormatObj)
	{
		//CGLDestroyPixelFormat : Calling this function is equivalent to calling CGLReleasePixelFormat.
		CGLReleasePixelFormat(m_pPixelFormatObj);
		m_pPixelFormatObj = NULL;
	}
}

BOOL	GL3OSXRenderWindow::InitializeOpenGL()
{
	//
	CGLPixelFormatAttribute attributes[] =
	{
		//From : OpenGL Programming Guide for Apple's Mac
		//kCGLOGLPVersion_Legacy (OSX 10.7) choose a renderer compatible with OpenGL1.0
		//kCGLOGLPVersion_GL3_Core (OSX 10.7) choose a renderer capable of OpenGL3.2 or later
		//kCGLOGLPVersion_GL4_Core (OSX 10.9) choose a renderer capable of OpenGL4.1 or later
		kCGLPFAOpenGLProfile, (CGLPixelFormatAttribute)kCGLOGLPVersion_GL3_Core,
		kCGLPFAColorSize, (CGLPixelFormatAttribute)32,
		kCGLPFAAlphaSize, (CGLPixelFormatAttribute)8,
		kCGLPFADepthSize, (CGLPixelFormatAttribute)16,
		kCGLPFAStencilSize, (CGLPixelFormatAttribute)8,
		kCGLPFAAccelerated,
		kCGLPFADoubleBuffer,
		(CGLPixelFormatAttribute)0
	};
	
	//
	GLint	nPixelFormatNum	= 0;
	m_pPixelFormatObj		= NULL;
	CGLError result = CGLChoosePixelFormat(attributes, &m_pPixelFormatObj, &nPixelFormatNum);
	if (result != kCGLNoError || m_pPixelFormatObj == NULL)
	{
		LogManager::getSingletonPtr()->LogMessage(LML_NORMAL, false, _T("<%s> CGLChoosePixelFormat fail [ERROR %d]"),
												  StringAToStringT(__FUNCTION__).c_str(), result);
		return FALSE;
	}
	
	m_pContextObj			= NULL;
	result = CGLCreateContext(m_pPixelFormatObj, NULL, &m_pContextObj);
	if (result != kCGLNoError || m_pContextObj == NULL)
	{
		LogManager::getSingletonPtr()->LogMessage(LML_NORMAL, false, _T("<%s> CGLCreateContext fail [ERROR %d]"),
												  StringAToStringT(__FUNCTION__).c_str(), result);
		return FALSE;
	}
	
	//
	result = CGLSetCurrentContext(m_pContextObj);
	if (result != kCGLNoError)
	{
		LogManager::getSingletonPtr()->LogMessage(LML_NORMAL, false, _T("<%s> CGLSetCurrentContext fail [ERROR %d]"),
												  StringAToStringT(__FUNCTION__).c_str(), result);
		return FALSE;
	}
	
	return TRUE;
}


VOID	GL3OSXRenderWindow::Resize(float width, float height)
{
	GL3RenderWindow::Resize(width, height);
	
	//
	
}


BOOL	GL3OSXRenderWindow::update()
{ 
	if(!GL3RenderWindow::update())
	{ return FALSE; }

	//
	return TRUE; 
}

VOID	GL3OSXRenderWindow::flush()
{
	if(m_pContextObj)
	{
		CGLFlushDrawable(m_pContextObj);
	}
	
	//
	return GL3RenderWindow::flush();
}
