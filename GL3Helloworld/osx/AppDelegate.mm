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
GL3Helloworld*		m_pHelloworld;

//
@implementation AppHelloworld

-(void)	Release
{
	if(m_pHelloworld)
	{
		m_pHelloworld->Release();
		MXE_DELETE_POINTER(m_pHelloworld);
	}
}

-(bool)	Initialize
{
	if(![super Initialize])
	{
		NSLog(@"<%s> Application initialize fail.", __FUNCTION__);
		return false;
	}
	
	m_pHelloworld = new GL3Helloworld();
	m_pHelloworld->ActiveRenderWindow(new GL3OSXRenderWindow());
	m_pHelloworld->ActiveRenderSystem(new GL3RenderSystem());
	if(!m_pHelloworld->Initialize())
	{
		NSLog(@"<%s> Application initialize fail.", __FUNCTION__);
		return false;
	}
	
	//
//	LogManager::getSingleton().LogMessage(LML_NORMAL, false, _T("<%S> Application 初始化完成了..."),
//										  StringAToStringT(__FUNCTION__).c_str());
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
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
	// Insert code here to tear down your application
	
	//必须手动调用父类方法
	[super applicationWillTerminate:aNotification];
}

@end
