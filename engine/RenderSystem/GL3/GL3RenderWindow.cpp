
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3RenderWindow.h"
#include "GL3RenderSystem.h"

//
GL3RenderWindow::GL3RenderWindow(void)
{
	m_fX			= 0.0f;
	m_fY			= 0.0f;
	
	m_nColorBits	= 32;
	m_nDepthBits	= 16;
	m_nStencilBits	= 1;
}

GL3RenderWindow::~GL3RenderWindow(void)
{
}

BOOL	GL3RenderWindow::DestroyRenderWindow()
{
	ReleaseOpenGL();

	return RenderWindow::DestroyRenderWindow();
}

BOOL	GL3RenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!RenderWindow::LoadRenderWindow(option_values)){ return FALSE; }


	//
	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("X")) == 0)
		{
			m_fX	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("Y")) == 0)
		{
			m_fY	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("ColorBits")) == 0)
		{
			m_nColorBits	= (int)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("DepthBits")) == 0)
		{
			m_nDepthBits	= (int)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("StencilBits")) == 0)
		{
			m_nStencilBits	= (int)i->second;
		}
	}

	//
	if(!InitializeOpenGL())
	{
		return FALSE;
	}

	return TRUE;
}

BOOL	GL3RenderWindow::update()
{ 
	if(!RenderWindow::update())
	{ return FALSE; }

	//
	glViewport((GLint)m_fX, (GLint)m_fY, (GLsizei)m_fWidth, (GLsizei)m_fHeight);

	//
	return TRUE; 
}

VOID	GL3RenderWindow::flush()
{
	//
	RenderWindow::flush();
}