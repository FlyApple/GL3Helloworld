
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3RenderWindow.h"


//
GL3RenderWindow::GL3RenderWindow(void)
{
	m_hDC		= NULL;
	m_hGLRC		= NULL;
	
	ZeroMemory(&m_PixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));

	m_fX		= 0.0f;
	m_fY		= 0.0f;
}

GL3RenderWindow::~GL3RenderWindow(void)
{
}

BOOL	GL3RenderWindow::DestroyRenderWindow()
{
	ReleaseOpenGL();

	if(m_hDC)
	{
		ReleaseDC(m_hWnd, m_hDC);
		m_hDC = NULL;
	}
	return RenderWindow_WIN::DestroyRenderWindow();
}

BOOL	GL3RenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!RenderWindow_WIN::LoadRenderWindow(option_values)){ return FALSE; }

	//
	m_hDC		= GetDC(m_hWnd);
	if(!m_hDC){ return FALSE; }

	//
	ZeroMemory(&m_PixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));
	m_PixelFormatDesc.nSize				= sizeof(PIXELFORMATDESCRIPTOR);
	m_PixelFormatDesc.nVersion			= 1;
	m_PixelFormatDesc.dwFlags			= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	m_PixelFormatDesc.iPixelType		= PFD_TYPE_RGBA;
	m_PixelFormatDesc.cColorBits		= 32;
	m_PixelFormatDesc.cDepthBits		= 16;
	m_PixelFormatDesc.cStencilBits		= 1;
	m_PixelFormatDesc.iLayerType		= PFD_MAIN_PLANE;	

	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("ColorBits")) == 0)
		{
			m_PixelFormatDesc.cColorBits	= (BYTE)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("DepthBits")) == 0)
		{
			m_PixelFormatDesc.cDepthBits	= (BYTE)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("StencilBits")) == 0)
		{
			m_PixelFormatDesc.cStencilBits	= (BYTE)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("X")) == 0)
		{
			m_fX	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("Y")) == 0)
		{
			m_fY	= (float)i->second;
		}
	}

	//
	if(!InitializeOpenGL())
	{
		return FALSE;
	}

	return TRUE;
}

VOID	GL3RenderWindow::ReleaseOpenGL()
{
	if(m_hGLRC)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hGLRC);

		m_hGLRC	= NULL;
	}
}

BOOL	GL3RenderWindow::InitializeOpenGL()
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


BOOL	GL3RenderWindow::RenderBegin(RenderSystem* pRenderSystem)
{ 
	if(!pRenderSystem){ return FALSE; }

	//
	glViewport((GLint)m_fX, (GLint)m_fY, (GLsizei)m_fWidth, (GLsizei)m_fHeight);

	return TRUE; 
}

BOOL	GL3RenderWindow::RenderEnd(RenderSystem* pRenderSystem)
{ 
	SwapBuffers(m_hDC);
	return TRUE; 
}