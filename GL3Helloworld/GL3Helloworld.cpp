// GL3Helloworld.cpp : 
//

#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3Helloworld.h"



//
GL3Helloworld::GL3Helloworld()
{

}

GL3Helloworld::~GL3Helloworld()
{

}

void	GL3Helloworld::Release()
{

	Application::Release();
}

bool	GL3Helloworld::Initialize()
{
	if(!Application::Initialize())
	{ return false; }

	//可在此處創建繪圖窗口和繪圖系統,或者在調用它之前進行創建
	//this->ActiveRenderWindow(new RenderWindow());

	return true;
}

BOOL	GL3Helloworld::InitInstance()
{
	if(!Application::InitInstance())
	{ return FALSE; }

	return TRUE;
}

BOOL	GL3Helloworld::ExitInstance()
{

	//
	return Application::ExitInstance();
}


VOID	GL3Helloworld::Rendering()
{
	//if(this->m_pRenderWindow)
	//{
	//}
}