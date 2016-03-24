//
//  CoreBase.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __MXE_CoreBase_H__
#define __MXE_CoreBase_H__

#pragma once

//
class CoreClass
{
public:
	CoreClass() {}
	virtual ~CoreClass() {}
};

//
class CoreInstance : public CoreClass
{
public:
	CoreInstance() {}
	virtual ~CoreInstance() {}
	
	virtual bool	Initialize()	= 0;
	virtual void	Release()		= 0;
};

#endif /* __MXE_CoreBase_H__ */
