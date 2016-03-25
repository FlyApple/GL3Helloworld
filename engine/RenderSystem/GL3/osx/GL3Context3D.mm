//
//  GLContext3D.cpp
//  GLTest
//
//  Created by enos sariel on 15/12/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "GL3Precompile.h"
#import "GL3Context3D.h"


//
@implementation GL3Context3D

@synthesize pixelFormatObj = m_PixelFormatObj;
-(CGLPixelFormatObj)pixelFormatObj
{
	return m_PixelFormatObj;
}

@synthesize contextObj = m_ContextObj;
-(CGLContextObj)contextObj
{
	return m_ContextObj;
}

- (id)init
{
	self = [super init];
	if (self != nil)
	{
		[self InitializeCGL];
	}
	return self;
}

- (void)dealloc
{
	[self ReleaseCGL];
}

- (BOOL)ReleaseCGL
{
	if(m_ContextObj)
	{
		CGLContextObj	ContextObj = CGLGetCurrentContext();
		if(ContextObj == m_ContextObj)
		{
			CGLSetCurrentContext(NULL);
		}
		
		CGLReleaseContext(m_ContextObj);
		m_ContextObj = NULL;
	}
	
	if(m_PixelFormatObj)
	{
		//CGLDestroyPixelFormat : Calling this function is equivalent to calling CGLReleasePixelFormat.
		CGLReleasePixelFormat(m_PixelFormatObj);
		m_PixelFormatObj = NULL;
	}
	return YES;
}

- (BOOL)InitializeCGL
{
	//
	CGLPixelFormatAttribute attributes[] =
	{
		//From : OpenGL Programming Guide for Apple's Mac
		//kCGLOGLPVersion_Legacy (OSX 10.7) choose a renderer compatible with OpenGL1.0
		//kCGLOGLPVersion_GL3_Core (OSX 10.7) choose a renderer capable of OpenGL3.2 or later
		//kCGLOGLPVersion_GL4_Core (OSX 10.9) choose a renderer capable of OpenGL4.1 or later
		kCGLPFAOpenGLProfile, (CGLPixelFormatAttribute)kCGLOGLPVersion_GL3_Core,
		kCGLPFAColorSize, (CGLPixelFormatAttribute)32,
		kCGLPFAAlphaSize, (CGLPixelFormatAttribute)8,
		kCGLPFADepthSize, (CGLPixelFormatAttribute)16,
		kCGLPFAStencilSize, (CGLPixelFormatAttribute)8,
		kCGLPFAAccelerated,
		kCGLPFADoubleBuffer,
		(CGLPixelFormatAttribute)0
	};
	
	//
	GLint	nPixelFormatNum	= 0;
	m_PixelFormatObj		= NULL;
	CGLError result = CGLChoosePixelFormat(attributes, &m_PixelFormatObj, &nPixelFormatNum);
	if (result != kCGLNoError || m_PixelFormatObj == NULL)
	{
		NSLog(@"<%s> CGLChoosePixelFormat fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}
	
	m_ContextObj			= NULL;
	result = CGLCreateContext(m_PixelFormatObj, NULL, &m_ContextObj);
	if (result != kCGLNoError || m_ContextObj == NULL)
	{
		NSLog(@"<%s> CGLCreateContext fail [ERROR %d]", __FUNCTION__, result);
		return NO;
	}
	
	//
	result = CGLSetCurrentContext(m_ContextObj);
	
	//
	return YES;
}

- (BOOL)update
{
	return YES;
}

- (BOOL)flush
{
	if(m_ContextObj)
	{
		CGLFlushDrawable(m_ContextObj);
	}
	return YES;
}

@end

