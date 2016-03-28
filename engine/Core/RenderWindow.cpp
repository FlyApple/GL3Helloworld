
#include "Precompile.h"
#include "RenderWindow.h"
#include "RenderSystem.h"

//
RenderWindow::RenderWindow(void)
{
	m_fWidth		= 0.0f;
	m_fHeight		= 0.0f;
}

RenderWindow::~RenderWindow(void)
{
}

BOOL	RenderWindow::DestroyRenderWindow()
{
	return TRUE;
}

BOOL	RenderWindow::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("Width")) == 0)
		{
			m_fWidth	= (float)i->second;
		}
		else if(_tcsicmp(i->first.c_str(), _T("Height")) == 0)
		{
			m_fHeight	= (float)i->second;
		}
	}

	//
	return TRUE;
}

VOID	RenderWindow::Resize(float width, float height)
{
	this->m_fWidth		= width;
	this->m_fHeight		= height;
}

BOOL	RenderWindow::update()
{
	return TRUE;
}

VOID	RenderWindow::flush()
{
	this->updateViewport();
}

