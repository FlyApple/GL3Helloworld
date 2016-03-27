//
//  GL3Device.hpp
//
//
//  Created by enos sariel on 15/12/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __GL3DeviceManager_H__
#define __GL3DeviceManager_H__

#pragma once

//
#include "Singleton.h"
#include "CoreBase.h"

//
class GL3Device
{
public:
	StringT			m_stringVersion;
	StringT			m_stringVendor;
	StringT			m_stringRenderer;
	StringT			m_stringShadingLanguage;
	StringArrayT	m_stringExtensions;
};

typedef std::vector<GL3Device*>	GL3DeviceArray;

//
class GL3DeviceManager : public SingletonT<GL3DeviceManager>, public CoreInstance
{
public:
	GL3DeviceManager();
	virtual ~GL3DeviceManager();
	
	virtual bool	Initialize();
	virtual void	Release();
	
	VOID			PrintDeviceInformation(GL3Device* pDevice = NULL);
	
private:
	GL3Device*		m_pCurrentDevice;
	GL3DeviceArray	m_DeviceList;
};


//
#endif /* __GL3DeviceManager_H__ */
