//
//  OSXApplication.m
//  GL3Helloworld
//
//  Created by enos sariel on 16/3/25.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#include "OSXApplication.h"

//
static OSXApplication*	gs_OSXApplicationInstancePtr = NULL;

//
@implementation OSXApplication

-(OSXApplication*)init
{
	self = [super init];
	if(self)
	{
	}
	
	gs_OSXApplicationInstancePtr = self;
	return self;
}

-(void)dealloc
{
	gs_OSXApplicationInstancePtr = NULL;
}

+(OSXApplication*)	InstancePtr
{
	return gs_OSXApplicationInstancePtr;
}

-(void)	Release
{
}

-(bool)	Initialize
{
	return true;
}


@end
