//
//  main.m
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "OSXApplication.h"


//int main(int argc, const char * argv[])
//{
//	return NSApplicationMain(argc, argv);
//}

OSXApplication*	g_pApplication = NULL;

int main(int argc, const char * argv[])
{
	g_pApplication = [OSXApplication new];
	
	return OSXApplicationMain(argc, argv);
}