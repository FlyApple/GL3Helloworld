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

	//���ڴ�̎�����L�D���ں��L�Dϵ�y,�������{����֮ǰ�M�Є���
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