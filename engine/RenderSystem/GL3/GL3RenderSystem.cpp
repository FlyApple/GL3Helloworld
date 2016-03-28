
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3RenderSystem.h"

#include "GL3DeviceManager.h"

#include "LogManager.h"



//
GL3RenderSystem::GL3RenderSystem(void)
{
	//
	m_pDeviceManager	= new GL3DeviceManager;
}

GL3RenderSystem::~GL3RenderSystem(void)
{
	//
	MXE_DELETE_POINTER(m_pDeviceManager);
}

void	GL3RenderSystem::Release()
{
	//
	m_pDeviceManager->Release();
	
	//
	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("[RenderSystem OpenGL V3] Release ending..."));

	//
	RenderSystem::Release();
}

bool	GL3RenderSystem::Initialize()
{
	if(!RenderSystem::Initialize())
	{ return false; }

	//
	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("[RenderSystem OpenGL V3] Initialize starting..."));

	//
	if (!m_pDeviceManager || !m_pDeviceManager->Initialize())
	{
		LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("<%s> m_pDeviceManager->Initialize() is fail."), __T_FUNCTION__);
		return false;
	}
	m_pDeviceManager->PrintDeviceInformation();
	

	//
	return true;
}


VOID	GL3RenderSystem::Render()
{
	RenderSystem::Render();
}