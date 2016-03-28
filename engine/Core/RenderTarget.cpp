
#include "Precompile.h"
#include "RenderTarget.h"

#include "Viewport.h"


//
RenderTarget::RenderTarget(void)
{
	m_pViewport		= NULL;
}

RenderTarget::~RenderTarget(void)
{
}


VOID	RenderTarget::updateViewport()
{
	if(m_pViewport)
	{ m_pViewport->update(); }
}
