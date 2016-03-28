#ifndef __MXE_RenderTarget_H__
#define __MXE_RenderTarget_H__

#pragma once

//
#include "CoreBase.h"

//
class Viewport;

//
class RenderTarget	: public CoreClass
{
public:
	RenderTarget(void);
	virtual ~RenderTarget(void);

	virtual BOOL	update()	= 0;
	virtual VOID	flush()		= 0;

protected:
	virtual	VOID	updateViewport();

protected:
	Viewport*		m_pViewport;
};


//
#endif //__MXE_RenderTarget_H__