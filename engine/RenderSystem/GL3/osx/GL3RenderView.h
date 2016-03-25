//
//  GL3RenderView.h
//
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "GL3Context3D.h"

//
@interface GL3RenderView : NSOpenGLView
{

@protected
	GL3Context3D*	m_pContext3D;
	
@private
	float			m_fWidth;
	float			m_fHeight;
	NSTimer*		m_pTimer;
}

@property(assign,readonly) float	renderWidth;
@property(assign,readonly) float	renderHeight;

- (GL3Context3D*)createContext3D;
- (BOOL)initializeOpenGL;
- (BOOL)releaseOpenGL;
- (void)render;

@end
