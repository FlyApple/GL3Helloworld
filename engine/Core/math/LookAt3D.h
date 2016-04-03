//
//  LookAt3D.h
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/3.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __LookAt3D_H__
#define __LookAt3D_H__

#pragma once

#include <math.h>
#include "Vector3D.h"
#include "Matrix3D.h"

//
namespace Math3D {
	
	//
	__inline Matrix4x4	LookAtLHM(Vector3 eyes, Vector3 at, Vector3 up)
	{
		Vector3		c = at - eyes;
		c.normalize();
		
		Vector3		a = up;
		a = a.crossProduct(c);
		a.normalize();
		
		Vector3		b = c;
		b = b.crossProduct(a);
		
		Matrix4x4	m =
		{
			a.x, b.x, c.x, 0.0f,
			a.y, b.y, c.y, 0.0f,
			a.z, b.z, c.z, 0.0f,
			
			-a.dotProduct(eyes),
			-b.dotProduct(eyes),
			-c.dotProduct(eyes),
			1.0f
		};
		return m;
	}
	
	//
	__inline Matrix4x4	LookAtRHM(Vector3 eyes, Vector3 at, Vector3 up)
	{
		Vector3		c = eyes - at;
		c.normalize();
		
		Vector3		a = up;
		a = a.crossProduct(c);
		a.normalize();
		
		Vector3		b = c;
		b = b.crossProduct(a);
		
		Matrix4x4	m =
		{
			a.x, b.x, c.x, 0.0f,
			a.y, b.y, c.y, 0.0f,
			a.z, b.z, c.z, 0.0f,
			
			-a.dotProduct(eyes),
			-b.dotProduct(eyes),
			-c.dotProduct(eyes),
			1.0f
		};
		return m;
	}
	
}; //namespace Math3D

#endif /* __LookAt3D_H__ */
