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
class RenderWindow;

//
class Application : public SingletonT<Application>, public CoreInstance
{
public:
	Application();
	virtual ~Application();
	
	virtual bool	Initialize();
	virtual void	Release();
	
	virtual BOOL	InitInstance();
	virtual BOOL	ExitInstance();

public:
	BOOL					ActiveRenderWindow(RenderWindow* pRenderWindow);
	template<typename Ty>	Ty*		ActiveRenderWindow(){ return reinterpret_cast<Ty*>(m_pRenderWindow); }

protected:
	RenderWindow*			m_pRenderWindow;
};

#endif /* __MXE_Application_H__ */
