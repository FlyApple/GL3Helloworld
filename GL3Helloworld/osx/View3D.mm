//
//  MyView3D.m
//  GLTest
//
//  Created by enos sariel on 15/12/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "View3D.h"

#include "Precompile.h"

#include "osx/GL3OSXRenderWindow.h"

#include "LogManager.h"

#include "GL3Helloworld.h"

//
extern GL3Helloworld*		g_pHelloworld;


//
@implementation View3D

- (GL3OSXRenderWindow*)loadOpenGLRenderWindow
{
	//
	StringDictionaryT<ULONG_PTR>	option_values;
	
	option_values[_T("X")]				= 0;
	option_values[_T("Y")]				= 0;
	option_values[_T("Width")]			= [self renderWidth];
	option_values[_T("Height")]			= [self renderHeight];
	
	option_values[_T("ColorBits")]		= 32;
	option_values[_T("DepthBits")]		= 16;
	option_values[_T("StencilBits")]	= 1;
	
	if(!g_pHelloworld->ActiveRenderWindow<GL3OSXRenderWindow>()->LoadRenderWindow(option_values))
	{
		LogManager::getSingleton().LogMessage(_T("<") + StringAToStringT(__FUNCTION__) + _T(">") +
											  _T(" LoadRenderWindow error."));
		return nil;
	}
	
	return g_pHelloworld->ActiveRenderWindow<GL3OSXRenderWindow>();
}

- (void)render
{
	if(g_pHelloworld)
	{ g_pHelloworld->Rendering(); }
}

@end
