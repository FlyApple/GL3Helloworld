//
//  GLContext3D.hpp
//  GLTest
//
//  Created by enos sariel on 15/12/20.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __GL3Context3D_H__
#define __GL3Context3D_H__

#import <Cocoa/Cocoa.h>

//
@interface GL3Context3D : NSObject
{
@private
	CGLPixelFormatObj	m_PixelFormatObj;
	CGLContextObj		m_ContextObj;
}

//
@property(assign,readonly) CGLPixelFormatObj	pixelFormatObj;
@property(assign,readonly) CGLContextObj		contextObj;

//
- (BOOL)InitializeCGL;
- (BOOL)ReleaseCGL;

- (BOOL)update;
- (BOOL)flush;

@end

#endif /* __GL3Context3D_H__ */
