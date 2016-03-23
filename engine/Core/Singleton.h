//
//  Singleton.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __MXE_Singleton_H__
#define __MXE_Singleton_H__

#pragma once

//
#include <assert.h>

//
template<typename _Ty>
class SingletonT
{
public:
	SingletonT()
	{
		ms_Singleton	= (_Ty*)this;
	}
	virtual ~SingletonT()
	{
		ms_Singleton	= NULL;
	}
	
	static _Ty*		getSingletonPtr(){ return ms_Singleton; }
	static _Ty&		getSingleton(){ return *ms_Singleton; }
private:
	static _Ty*		ms_Singleton;
};
#define SINGLETON_IMPLE(_Ty)	template<typename _Ty>	_Ty* SingletonT<_Ty>::ms_Singleton = NULL;


#endif /* __MXE_Singleton_H__ */
