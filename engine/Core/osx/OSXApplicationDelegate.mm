//
//  ApplicationDelegate.m
//  GLTest
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "OSXApplicationDelegate.h"


@implementation OSXApplicationDelegate

// 再关闭主窗口时退出程序，嗯就这酱紫的。
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
	return YES;
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender;
{
	//由于是自然退出，将不会被调用，必须手动调用，以回应代码.
	[self applicationWillTerminate:[NSNotification alloc]];
	
	//停止程序
	[NSApp stop:nil];
	
	//必须用postEvent进行提交事件，以便让循环检测并退出循环；
	[NSApp postEvent:[NSEvent otherEventWithType:NSApplicationDefined
										location:NSMakePoint(0.0f, 0.0f)
								   modifierFlags:0
									   timestamp:0
									windowNumber:0
										 context:nil
										 subtype:0 data1:0 data2:0]
			 atStart:YES];
	
	//暂时不结束，让循环退出自然结束
	return NSTerminateCancel;
}

- (void)applicationWillFinishLaunching:(NSNotification *)aNotification
{
	// Insert code here to initialize your application
	
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
	// Insert code here to tear down your application
	
}

@end
