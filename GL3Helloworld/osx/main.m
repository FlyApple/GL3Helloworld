//
//  main.m
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/24.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "AppDelegate.h"


//int main(int argc, const char * argv[])
//{
//	return NSApplicationMain(argc, argv);
//}

AppHelloworld*	g_pApplication = NULL;

int main(int argc, const char * argv[])
{
	g_pApplication = [[AppHelloworld new] init];
	
	return OSXApplicationMain(argc, argv);
}