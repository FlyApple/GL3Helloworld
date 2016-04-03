// GL3Helloworld.cpp : 
//

#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3Helloworld.h"

#include "GL3RenderSystem.h"
#include "GL3RenderWindow.h"

#include "math/Perspective3D.h"
#include "math/LookAt3D.h"

//
GL3Helloworld::GL3Helloworld()
{

}

GL3Helloworld::~GL3Helloworld()
{

}

void	GL3Helloworld::Release()
{

	Application::Release();
}

bool	GL3Helloworld::Initialize()
{
	if(!Application::Initialize())
	{ return false; }

	//ø…‘⁄¥ÀÃéÑìΩ®¿LàD¥∞ø⁄∫Õ¿LàDœµΩy,ªÚ’ﬂ‘⁄’{”√À¸÷Æ«∞ﬂM––ÑìΩ®
	//this->ActiveRenderWindow(new RenderWindow());
	//this->ActiveRenderSystem(new RenderSystem());

	return true;
}

BOOL	GL3Helloworld::InitInstance()
{
	if(!Application::InitInstance())
	{ return FALSE; }

	if(!m_pActiveRenderSystem || !m_pActiveRenderSystem->Initialize())
	{ return FALSE; }

	Math3D::Matrix4x4	pm;
	pm = Math3D::Matrix4x4::IDENTITY;
	pm = Math3D::PerspectiveFOVRHM(this->ActiveRenderWindow<GL3RenderWindow>()->getWidth()/
													   this->ActiveRenderWindow<GL3RenderWindow>()->getHeight(),
													   45.0f, 0.1f, 1000.0f);

	Math3D::Matrix4x4	vm;
	vm = Math3D::Matrix4x4::IDENTITY;
	vm = Math3D::LookAtRHM(Math3D::Vector3(0.0f, 0.0f, 1.0f),
											   Math3D::Vector3(0.0f, 0.0f, 0.0f),
											   Math3D::Vector3::AXIS_Y);
	
	return TRUE;
}

BOOL	GL3Helloworld::ExitInstance()
{
	//
	return Application::ExitInstance();
}
