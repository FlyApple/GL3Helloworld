//
//  Perspective3D.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/3.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __Perspective3D_H__
#define __Perspective3D_H__

#pragma once


#include <math.h>
#include "Matrix3D.h"

//
namespace Math3D {
	
	//
	__inline Matrix4x4	PerspectiveFOVLHM(float aspect = 0.0f, float fov= 45.0f, float near = 0.1f, float far = 1000.0f)
	{
		float scale_y = 1.0f/tan(fov * 0.5f);
		float scale_x = scale_y / aspect;
		Matrix4x4	m =
		{
			scale_x, 0.0f, 0.0f, 0.0f,
			0.0f, scale_y, 0.0f, 0.0f,
			0.0f, 0.0f, far/(far-near), 1.0f,
			0.0f, 0.0f, (near*far)/(near-far), 0.0f
		};
		return m;
	}
	
	//
	__inline Matrix4x4	PerspectiveFOVRHM(float aspect = 0.0f, float fov= 45.0f, float near = 0.1f, float far = 1000.0f)
	{
		float scale_y = 1.0f/tan(fov * 0.5f);
		float scale_x = scale_y / aspect;
		Matrix4x4	m =
		{
			scale_x, 0.0f, 0.0f, 0.0f,
			0.0f, scale_y, 0.0f, 0.0f,
			0.0f, 0.0f, far/(far-near), -1.0f,
			0.0f, 0.0f, (near*far)/(near-far), 0.0f
		};
		return m;
	}
	
}; //namespace Math3D

#endif /* __Perspective3D_H__ */
