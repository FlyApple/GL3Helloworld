//
//  Application.hpp
//  
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXE_Application_H__
#define __MXE_Application_H__

#pragma once

//
#include "Singleton.h"
#include "CoreBase.h"

//
class LogManager;
class RenderWindow;
class RenderSystem;

//
class Application : public SingletonT<Application>, public CoreInstance
{
public:
	Application(const StringT& stringLogFileName = _T("Application.log"));
	virtual ~Application();
	
	virtual bool	Initialize();
	virtual void	Release();
	
	virtual BOOL	InitInstance();
	virtual BOOL	ExitInstance();

	virtual VOID	Rendering();

private:
	StringT					m_stringVersion;
	LogManager*				m_pLogManager;

public:
	BOOL					ActiveRenderWindow(RenderWindow* pRenderWindow);
	template<typename Ty>	Ty*		ActiveRenderWindow(){ return reinterpret_cast<Ty*>(m_pActiveRenderWindow); }

	BOOL					ActiveRenderSystem(RenderSystem* pRenderSystem);
	template<typename Ty>	Ty*		ActiveRenderSystem(){ return reinterpret_cast<Ty*>(m_pActiveRenderSystem); }

protected:
	RenderWindow*			m_pActiveRenderWindow;
	RenderSystem*			m_pActiveRenderSystem;
};

#endif /* __MXE_Application_H__ */
