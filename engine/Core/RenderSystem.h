#ifndef __MXE_RenderSystem_H__
#define __MXE_RenderSystem_H__

#pragma once

//
#include "CoreBase.h"

//
class RenderSystem	: public CoreInstance
{
public:
	RenderSystem(void);
	virtual ~RenderSystem(void);

	virtual bool	Initialize();
	virtual void	Release();

	virtual VOID	Render();

protected:

};


//
#endif //__MXE_RenderSystem_H__