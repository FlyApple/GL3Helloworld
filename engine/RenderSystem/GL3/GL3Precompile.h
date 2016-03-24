//
//  GL3Precompile.h
//  
//
//  Created by enos sariel on 15/12/19.
//  Copyright © 2015年 enos sariel. All rights reserved.
//

#ifndef __MXE_GL3Precompile_H__
#define __MXE_GL3Precompile_H__

#pragma once


//
#if defined (__APPLE__)

#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#include <OpenGL/OpenGL.h>

#elif defined (_MSC_VER)

//
#define GLEW_STATIC
#include "GL/glew.h"
#include "GL/wglew.h"


#pragma comment( lib, "opengl32.lib" )
#pragma comment( lib, "glu32.lib" )


#endif



//
#endif /* __MXE_GL3Precompile_H__ */
