#ifndef __MXE_Viewport_H__
#define __MXE_Viewport_H__

#pragma once

//
#include "CoreBase.h"

//
class Viewport	: public CoreClass
{
public:
	Viewport(void);
	virtual ~Viewport(void);

	virtual BOOL	update();

protected:
};


//
#endif //__MXE_Viewport_H__