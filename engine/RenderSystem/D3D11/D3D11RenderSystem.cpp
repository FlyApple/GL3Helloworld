
#include "Precompile.h"
#include "D3D11Precompile.h"
#include "D3D11RenderSystem.h"

#include "LogManager.h"



//
D3D11RenderSystem::D3D11RenderSystem(void)
{
}

D3D11RenderSystem::~D3D11RenderSystem(void)
{
}

void	D3D11RenderSystem::Release()
{
	
	//
	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("[RenderSystem Direct3D11] Release ending..."));

	//
	RenderSystem::Release();
}

bool	D3D11RenderSystem::Initialize()
{
	if(!RenderSystem::Initialize())
	{ return false; }

	//
	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("[RenderSystem Direct3D11] Initialize starting..."));
	

	//
	return true;
}


VOID	D3D11RenderSystem::Render()
{
	RenderSystem::Render();
}