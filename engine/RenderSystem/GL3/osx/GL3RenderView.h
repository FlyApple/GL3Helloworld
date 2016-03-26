//
//  GL3RenderView.h
//
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//
class GL3OSXRenderWindow;

//
@interface GL3RenderView : NSOpenGLView
{
@protected
	GL3OSXRenderWindow*	m_pRenderWindow;
	
@private
	float			m_fWidth;
	float			m_fHeight;
	NSTimer*		m_pTimer;
}

@property(assign,readonly) float	renderWidth;
@property(assign,readonly) float	renderHeight;

- (GL3OSXRenderWindow*)loadOpenGLRenderWindow;
- (BOOL)initializeOpenGL;
- (BOOL)releaseOpenGL;
- (void)render;

@end
