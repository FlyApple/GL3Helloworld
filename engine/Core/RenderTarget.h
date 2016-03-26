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

	virtual BOOL	Update(RenderSystem* pRenderSystem) = 0;
	
protected:
};


//
#endif //__MXE_RenderTarget_H__