#ifndef __MXE_RenderTarget_H__
#define __MXE_RenderTarget_H__

#pragma once

//
#include "CoreBase.h"

//
class RenderSystem;

//
class RenderTarget	: public CoreClass
{
public:
	RenderTarget(void);
	virtual ~RenderTarget(void);

	virtual	BOOL	RenderBegin(RenderSystem* pRenderSystem)	= 0;
	virtual BOOL	RenderEnd(RenderSystem* pRenderSystem)		= 0;
};


//
#endif //__MXE_RenderTarget_H__