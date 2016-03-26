//
//  GLRenderWindow.m
//  GLTest
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import "GL3RenderView.h"

#include "Precompile.h"
#include "GL3Precompile.h"
#include "GL3OSXRenderWindow.h"

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
		m_pRenderWindow	= [self loadOpenGLRenderWindow];
		if(m_pRenderWindow)
		{
			CGLContextObj	pContextObj	= m_pRenderWindow->getCGLContextObj();
			CGLPixelFormatObj	pPixelFormatObj = m_pRenderWindow->getCGLPixelFormatObj();
			
			NSOpenGLPixelFormat*	pixel_format	= [[NSOpenGLPixelFormat alloc] initWithCGLPixelFormatObj:pPixelFormatObj];
			NSOpenGLContext*		context			= [[NSOpenGLContext alloc] initWithCGLContextObj:pContextObj];
			if(context)
			{
				[self setPixelFormat:pixel_format];
				[self setOpenGLContext:context];
			}
	
		}
	}
	return self;
}

- (GL3OSXRenderWindow*)loadOpenGLRenderWindow
{
	return nil;
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
	
	//
	if(m_pRenderWindow)
	{ m_pRenderWindow->Resize(m_fWidth, m_fHeight); }
}

- (void)idle:(NSTimer*)pTimer
{
	[self drawRect:[self bounds]];
}

- (void)drawRect:(NSRect)dirtyRect
{
	[super drawRect:dirtyRect];
	
	// Drawing code here.
	
	[self render];
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
