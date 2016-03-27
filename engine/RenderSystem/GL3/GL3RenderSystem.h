#ifndef __MXE_GL3RenderSystem_H__
#define __MXE_GL3RenderSystem_H__

#pragma once

//
#include "RenderSystem.h"

//
class GL3DeviceManager;

//
class GL3RenderSystem	: public RenderSystem
{
public:
	GL3RenderSystem(void);
	virtual ~GL3RenderSystem(void);

	virtual bool	Initialize();
	virtual void	Release();

	virtual VOID	Render();
	
private:
	GL3DeviceManager*		m_pDeviceManager;
};


//
#endif //__MXE_GL3RenderSystem_H__