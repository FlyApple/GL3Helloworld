//
//  Application.cpp
//  
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "Application.h"
#include "RenderWindow.h"

//
SINGLETON_IMPLE(Application)
Application::Application()
{
	//
	m_pRenderWindow		= NULL;
}

Application::~Application()
{
}

void	Application::Release()
{
	//
	MXE_DELETE_POINTER(m_pRenderWindow);
}

bool	Application::Initialize()
{
	return true;
}

BOOL	Application::ExitInstance()
{
	if(m_pRenderWindow)
	{ m_pRenderWindow->DestroyRenderWindow(); }

	return FALSE;
}

BOOL	Application::InitInstance()
{
	return TRUE;
}

BOOL	Application::ActiveRenderWindow(RenderWindow* pRenderWindow)
{
	m_pRenderWindow	= pRenderWindow;
	return TRUE;
}