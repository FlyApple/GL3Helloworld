#ifndef __MXE_D3D11RenderSystem_H__
#define __MXE_D3D11RenderSystem_H__

#pragma once

//
#include "RenderSystem.h"


//
class D3D11RenderSystem	: public RenderSystem
{
public:
	D3D11RenderSystem(void);
	virtual ~D3D11RenderSystem(void);

	virtual bool	Initialize();
	virtual void	Release();

	virtual VOID	Render();
	
private:

};


//
#endif //__MXE_D3D11RenderSystem_H__