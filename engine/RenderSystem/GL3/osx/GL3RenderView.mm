//
//  GLRenderWindow.m
//  GLTest
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "GL3Precompile.h"
#import "GL3RenderView.h"


//
@implementation GL3RenderView

//
@synthesize renderWidth = m_fWidth;
- (float)renderWidth{ return m_fWidth; }
@synthesize renderHeight = m_fHeight;
- (float)renderHeight{ return m_fHeight; }


//
- (id)initWithCoder:(NSCoder *)coder
{
	self = [super initWithCoder:coder];
	if(self != nil)
	{
		m_pContext3D	= [self createContext3D];
		
		NSOpenGLPixelFormat*	pixel_format	= [[NSOpenGLPixelFormat alloc] initWithCGLPixelFormatObj:[m_pContext3D pixelFormatObj]];
		NSOpenGLContext*		context			= [[NSOpenGLContext alloc] initWithCGLContextObj:[m_pContext3D contextObj]];
		if(context)
		{
			[self setPixelFormat:pixel_format];
			[self setOpenGLContext:context];
		}
	}
	return self;
}


- (GL3Context3D*)createContext3D
{
	return [[GL3Context3D alloc] init];
}

- (void)clearGLContext
{
	[self releaseOpenGL];
	
	[super clearGLContext];
}

- (void)prepareOpenGL
{
	[super prepareOpenGL];
	
	//
	m_pTimer = [NSTimer timerWithTimeInterval:(1.0f/60.0f)target:self selector:@selector(idle:) userInfo:nil repeats:YES];
	[[NSRunLoop currentRunLoop]addTimer:m_pTimer forMode:NSDefaultRunLoopMode];
	
	//
	m_fWidth = [self bounds].size.width;
	m_fHeight= [self bounds].size.height;
	
	//
	[self initializeOpenGL];
}

- (void)reshape
{
	m_fWidth = [self bounds].size.width;
	m_fHeight= [self bounds].size.height;
}

- (void)idle:(NSTimer*)pTimer
{
	[self drawRect:[self bounds]];
}

- (void)drawRect:(NSRect)dirtyRect
{
	[super drawRect:dirtyRect];
	
	// Drawing code here.
	
	if(m_pContext3D)
	{
		[m_pContext3D update];
		
		[self render];
		
		[m_pContext3D flush];
	}
}

- (BOOL)releaseOpenGL
{
	//nothing
	return YES;
}

- (BOOL)initializeOpenGL
{
	//nothing
	return YES;
}

- (void)render
{
}

@end
