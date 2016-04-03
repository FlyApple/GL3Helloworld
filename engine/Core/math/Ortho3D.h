//
//  Ortho3D.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/3.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __Ortho3D_H__
#define __Ortho3D_H__

#pragma once

#include <math.h>
#include "Matrix3D.h"

//
namespace Math3D {
	
	//
	__inline Matrix4x4	OrthoLHM(float width, float height, float near = 0.1f, float far = 1000.0f)
	{
		Matrix4x4	m =
		{
			2.0f/width, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f/height, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f/(far-near), 0.0f,
			0.0f, 0.0f, near/(near-far), 1.0f
		};
		return m;
	}
	
	//
	__inline Matrix4x4	OrthoRHM(float width, float height, float near = 0.1f, float far = 1000.0f)
	{
		Matrix4x4	m =
		{
			2.0f/width, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f/height, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f/(near-far), 0.0f,
			0.0f, 0.0f, near/(near-far), 1.0f
		};
		return m;
	}
	
}; //namespace Math3D

#endif /* __Ortho3D_H__ */
