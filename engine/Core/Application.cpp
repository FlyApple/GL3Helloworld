//
//  Application.cpp
//  
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "Application.h"

#include "LogManager.h"
#include "RenderWindow.h"
#include "RenderSystem.h"


//
SINGLETON_IMPLE(Application)
Application::Application(const StringT& stringLogFileName)
{
	//
	m_stringVersion		= _T("1.00");

	// Create log manager and default log file if there is no log manager yet
	if(LogManager::getSingletonPtr() == NULL)
	{
		m_pLogManager = new LogManager( );
		if(m_pLogManager->Initialize())
		{ m_pLogManager->CreateLog(stringLogFileName, true, true); }
		else
		{
			throw _T("<LogManager> Initialize error.");
			return;
		}
	}

	//
	m_pActiveRenderWindow		= NULL;
	m_pActiveRenderSystem		= NULL;


	//
	StringT	message = _T("--------^^** [Magic X Engine] Initialize ");
	message			= message + _T("[Version: ") + m_stringVersion + _T(" ] ");
	message			= message + _T("**^^--------");
	LogManager::getSingleton().LogMessage(message);
}

Application::~Application()
{
	MXE_DELETE_POINTER(m_pLogManager);
}

void	Application::Release()
{
	//
	MXE_DELETE_POINTER(m_pActiveRenderSystem);
	MXE_DELETE_POINTER(m_pActiveRenderWindow);

	//
	LogManager::getSingleton().LogMessage(_T("--------- [Magic X Engine] Release ----------"));

	//
	m_pLogManager->Release();
}

bool	Application::Initialize()
{
	return true;
}

BOOL	Application::ExitInstance()
{
	if(m_pActiveRenderSystem)
	{ m_pActiveRenderSystem->Release(); }

	if(m_pActiveRenderWindow)
	{ m_pActiveRenderWindow->DestroyRenderWindow(); }

	return TRUE;
}

BOOL	Application::InitInstance()
{
	return TRUE;
}

BOOL	Application::ActiveRenderWindow(RenderWindow* pRenderWindow)
{
	m_pActiveRenderWindow	= pRenderWindow;
	return TRUE;
}

BOOL	Application::ActiveRenderSystem(RenderSystem* pRenderSystem)
{
	m_pActiveRenderSystem	= pRenderSystem;
	return TRUE;
}

VOID	Application::Rendering()
{
	if(m_pActiveRenderWindow)
	{
		if(m_pActiveRenderWindow->update())
		{ m_pActiveRenderWindow->flush(); }
	}
}