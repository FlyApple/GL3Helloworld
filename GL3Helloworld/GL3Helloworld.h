#ifndef __GL3Helloworld_H__
#define __GL3Helloworld_H__

#pragma once


//
#include "Application.h"

//
class GL3Helloworld		:	public Application
{
public:
	GL3Helloworld();
	virtual ~GL3Helloworld();

	virtual bool	Initialize();
	virtual void	Release();

	virtual BOOL	InitInstance();
	virtual BOOL	ExitInstance();

	virtual VOID	Rendering();

private:

};

//
#endif //__GL3Helloworld_H__