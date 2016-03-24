
#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3RenderSystem.h"


//
GL3RenderSystem::GL3RenderSystem(void)
{

}

GL3RenderSystem::~GL3RenderSystem(void)
{
}

void	GL3RenderSystem::Release()
{

	//
	RenderSystem::Release();
}

bool	GL3RenderSystem::Initialize()
{
	if(!RenderSystem::Initialize())
	{ return false; }


	return true;
}


VOID	GL3RenderSystem::Render()
{
	RenderSystem::Render();
}