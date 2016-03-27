//
//  GLDevice3D.cpp
//  GLTest
//
//  Created by enos sariel on 15/12/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3DeviceManager.h"

#include "LogManager.h"


//
SINGLETON_IMPLE(GL3DeviceManager);
GL3DeviceManager::GL3DeviceManager()
{
	m_pCurrentDevice = NULL;
}

GL3DeviceManager::~GL3DeviceManager()
{
}

void	GL3DeviceManager::Release()
{
	for(GL3DeviceArray::iterator i = m_DeviceList.begin(); i != m_DeviceList.end(); )
	{
		GL3Device*	device = *i;
		i = m_DeviceList.erase(i);
		
		if (m_pCurrentDevice == device)
		{ m_pCurrentDevice = NULL; }
		
		MXE_DELETE_POINTER(device);
	}
}

bool	GL3DeviceManager::Initialize()
{
	//
	const char*		desc	= NULL;
	GL3Device*		device	= new GL3Device();
	device->m_stringVersion			= !(desc = (const char*)glGetString(GL_VERSION)) ? _T("") : StringAToStringT(desc);
	device->m_stringVendor			= !(desc = (const char*)glGetString(GL_VENDOR)) ? _T("") : StringAToStringT(desc);
	device->m_stringRenderer		= !(desc = (const char*)glGetString(GL_RENDERER)) ? _T("") : StringAToStringT(desc);
	device->m_stringShadingLanguage	= !(desc = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION)) ? _T("") : StringAToStringT(desc);
	
	//
	int count = 0;
	glGetIntegerv(GL_NUM_EXTENSIONS, &count);
	for (int n = 0; n < count; n++)
	{
		desc = (const char*)glGetStringi(GL_EXTENSIONS, n);
		device->m_stringExtensions.push_back(!desc ? _T("") : StringAToStringT(desc));
	}
	
	//
	if(!m_pCurrentDevice)
	{ m_pCurrentDevice = device; }
	
	//
	m_DeviceList.push_back(device);
	return true;
}

VOID	GL3DeviceManager::PrintDeviceInformation(GL3Device* pDevice)
{
	if(pDevice == NULL){ pDevice = m_pCurrentDevice; }
	if(pDevice == NULL){ return; }
	
	//
	LogManager::getSingleton().LogMessage(_T("[GL3DeviceManager] OpenGL version ") + pDevice->m_stringVersion);
	LogManager::getSingleton().LogMessage(_T("[GL3DeviceManager] OpenGL vendor ") + pDevice->m_stringVendor);
	LogManager::getSingleton().LogMessage(_T("[GL3DeviceManager] OpenGL renderer ") + pDevice->m_stringRenderer);
	LogManager::getSingleton().LogMessage(_T("[GL3DeviceManager] OpenGL GLSL Version ") + pDevice->m_stringShadingLanguage);
	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("[GL3DeviceManager] OpenGL extensions count %d"),
										  pDevice->m_stringExtensions.size());
	
	//
	for (int i = 0; i < (long)pDevice->m_stringExtensions.size(); i++)
	{
		LogManager::getSingleton().LogMessage(pDevice->m_stringExtensions[i]);
	}
}
