//
//  AppDelegate.m
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#import "AppDelegate.h"

#include "Precompile.h"

#include "osx/GL3OSXRenderWindow.h"
#include "GL3RenderSystem.h"

#include "LogManager.h"

#include "GL3Helloworld.h"


//
GL3Helloworld*		g_pHelloworld;

//
@implementation AppHelloworld

-(void)	Release
{
	if(g_pHelloworld)
	{
		g_pHelloworld->Release();
		MXE_DELETE_POINTER(g_pHelloworld);
	}
}

-(bool)	Initialize
{
	if(![super Initialize])
	{
		NSLog(@"<%s> Application initialize fail.", __FUNCTION__);
		return false;
	}
	
	g_pHelloworld = new GL3Helloworld();
	g_pHelloworld->ActiveRenderWindow(new GL3OSXRenderWindow());
	g_pHelloworld->ActiveRenderSystem(new GL3RenderSystem());
	if(!g_pHelloworld->Initialize())
	{
		NSLog(@"<%s> Application initialize fail.", __FUNCTION__);
		return false;
	}
	
	//
	//LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("<%s> Application 初始化完成了..."), __T_FUNCTION__);
	return true;
}

@end

//
@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end


//
@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
	
	if(!g_pHelloworld || !g_pHelloworld->InitInstance())
	{
		LogManager::getSingleton().LogMessage(_T("<") + StringAToStringT(__FUNCTION__) + _T(">") +
											  _T(" InitInstance error."));
		return ;
	}
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
	// Insert code here to tear down your application
	
	if(g_pHelloworld)
	{ g_pHelloworld->ExitInstance(); }
	
	//必须手动调用父类方法
	[super applicationWillTerminate:aNotification];
}

@end
