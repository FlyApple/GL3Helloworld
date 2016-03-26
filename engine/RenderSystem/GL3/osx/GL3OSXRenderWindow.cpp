
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3OSXRenderWindow.h"


//
GL3OSXRenderWindow::GL3OSXRenderWindow(void)
{
}

GL3OSXRenderWindow::~GL3OSXRenderWindow(void)
{
}

BOOL	GL3OSXRenderWindow::DestroyRenderWindow()
{
	ReleaseOpenGL();

	return GL3RenderWindow::DestroyRenderWindow();
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
}

BOOL	GL3OSXRenderWindow::InitializeOpenGL()
{
	
	
	return TRUE;
}


BOOL	GL3OSXRenderWindow::onRenderBegin(RenderSystem* pRenderSystem)
{ 
	if(!GL3RenderWindow::onRenderBegin(pRenderSystem))
	{ return FALSE; }

	//
	return TRUE; 
}

BOOL	GL3OSXRenderWindow::onRenderEnd(RenderSystem* pRenderSystem)
{ 
	//
	return GL3RenderWindow::onRenderEnd(pRenderSystem);
}
