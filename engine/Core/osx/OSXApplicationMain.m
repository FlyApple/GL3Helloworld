//
//  OSXApplication.m
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/25.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#include "OSXApplication.h"

//
#ifdef _MXE_OSX_MAIN_
int		OSXApplicationMain(int argc, const char * argv[])
{
	[[OSXApplication InstancePtr] Initialize];
	
	NSApplication* pApplication = [NSApplication sharedApplication];
	if(pApplication)
	{
		//		GLApplicationDelegate* pDelegate = [[GLApplicationDelegate alloc] init];
		//		[pApplication setDelegate:pDelegate];
		
		[[NSBundle mainBundle] loadNibNamed:@"MainMenu" owner:NSApp topLevelObjects:nil];
		
		[pApplication run];
	}
	
	[[OSXApplication InstancePtr] Release];
	return 0;
}
#else
int		OSXApplicationMain(int argc, const char * argv[])
{
	[[OSXApplication InstancePtr] Initialize];
	
	int result = NSApplicationMain(argc, argv);
	
	[[OSXApplication InstancePtr] Release];
	return result;
}
#endif
