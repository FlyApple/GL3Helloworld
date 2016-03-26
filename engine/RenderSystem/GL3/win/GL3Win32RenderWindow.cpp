
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3Win32RenderWindow.h"


//
GL3Win32RenderWindow::GL3Win32RenderWindow(void)
{
	m_hWnd		= NULL;
	m_hDC		= NULL;
	m_hGLRC		= NULL;
	
	ZeroMemory(&m_PixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));
}

GL3Win32RenderWindow::~GL3Win32RenderWindow(void)
{
}

BOOL	GL3Win32RenderWindow::DestroyRenderWindow()
{
	ReleaseOpenGL();

	if(m_hDC)
	{
		ReleaseDC(m_hWnd, m_hDC);
		m_hDC = NULL;
	}
	return GL3RenderWindow::DestroyRenderWindow();
}

BOOL	GL3Win32RenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!GL3RenderWindow::LoadRenderWindow(option_values)){ return FALSE; }

	//
	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("HANDLE")) == 0)
		{
			m_hWnd	= (HWND)i->second;
		}
	}

	//
	m_hDC		= GetDC(m_hWnd);
	if(!m_hDC){ return FALSE; }

	//
	ZeroMemory(&m_PixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));
	m_PixelFormatDesc.nSize				= sizeof(PIXELFORMATDESCRIPTOR);
	m_PixelFormatDesc.nVersion			= 1;
	m_PixelFormatDesc.dwFlags			= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	m_PixelFormatDesc.iPixelType		= PFD_TYPE_RGBA;
	m_PixelFormatDesc.cColorBits		= (BYTE)m_nColorBits;
	m_PixelFormatDesc.cDepthBits		= (BYTE)m_nDepthBits;
	m_PixelFormatDesc.cStencilBits		= (BYTE)m_nStencilBits;
	m_PixelFormatDesc.iLayerType		= PFD_MAIN_PLANE;	

	//
	if(!InitializeOpenGL())
	{
		return FALSE;
	}

	return TRUE;
}

VOID	GL3Win32RenderWindow::ReleaseOpenGL()
{
	if(m_hGLRC)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hGLRC);

		m_hGLRC	= NULL;
	}
}

BOOL	GL3Win32RenderWindow::InitializeOpenGL()
{
	int nPixelFormat = ChoosePixelFormat(m_hDC, &m_PixelFormatDesc);
	if(nPixelFormat == 0){ return FALSE; }

	SetPixelFormat(m_hDC, nPixelFormat, &m_PixelFormatDesc);

	m_hGLRC	= wglCreateContext(m_hDC);
	if(m_hGLRC == NULL){ return FALSE; }

	if(!wglMakeCurrent(m_hDC, m_hGLRC))
	{
		return FALSE;
	}

	//
	GLenum		result = glewInit( );
	if( result != GLEW_OK)
	{ 
		return FALSE; 
	}

	//
	GLint attribs[] =
	{
		WGL_CONTEXT_MAJOR_VERSION_ARB,	3,
		WGL_CONTEXT_MINOR_VERSION_ARB,	1,
		WGL_CONTEXT_FLAGS_ARB,			0,
		0
	};

	HGLRC hGLRC = NULL;
	if(!wglewIsSupported("WGL_ARB_create_context") || (hGLRC = wglCreateContextAttribsARB(m_hDC, 0, attribs)) == NULL)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hGLRC);
		m_hGLRC	= NULL;
		return FALSE;
	}
	else
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hGLRC);
		wglMakeCurrent(m_hDC, hGLRC);
		m_hGLRC	= hGLRC;
	}

	return TRUE;
}


BOOL	GL3Win32RenderWindow::onRenderBegin(RenderSystem* pRenderSystem)
{ 
	if(!GL3RenderWindow::onRenderBegin(pRenderSystem))
	{ return FALSE; }

	//
	return TRUE; 
}

BOOL	GL3Win32RenderWindow::onRenderEnd(RenderSystem* pRenderSystem)
{ 
	SwapBuffers(m_hDC);
	return GL3RenderWindow::onRenderEnd(pRenderSystem); 
}
