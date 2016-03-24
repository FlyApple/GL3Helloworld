
#include "Precompile.h"
#include "RenderWindow_WIN.h"


//
RenderWindow_WIN::RenderWindow_WIN(void)
{
	m_hWnd			= NULL;
}

RenderWindow_WIN::~RenderWindow_WIN(void)
{
}

BOOL	RenderWindow_WIN::DestroyRenderWindow()
{
	//
	return RenderWindow::DestroyRenderWindow();
}

BOOL	RenderWindow_WIN::LoadRenderWindow(const StringDictionaryT<ULONG_PTR>& option_values)
{
	if(!RenderWindow::LoadRenderWindow(option_values))
	{ return FALSE; }

	for(StringDictionaryT<ULONG_PTR>::const_iterator i = option_values.begin(); i != option_values.end(); i ++)
	{
		if(_tcsicmp(i->first.c_str(), _T("HANDLE")) == 0)
		{
			m_hWnd	= (HWND)i->second;
		}
	}

	//
	return TRUE;
}