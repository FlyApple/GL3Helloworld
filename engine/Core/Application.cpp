//
//  Application.cpp
//  GLTest
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "Application.h"


//
SINGLETON_IMPLE(Application)
Application::Application()
{
}

Application::~Application()
{
}

void	Application::Release()
{

}

bool	Application::Initialize()
{
	return true;
}

BOOL	Application::ExitInstance()
{
	return FALSE;
}

BOOL	Application::InitInstance()
{
	return TRUE;
}

