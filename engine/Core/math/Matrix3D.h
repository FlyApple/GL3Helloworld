//
//  Matrix3D.hpp
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/3.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __Matrix3D_H__
#define __Matrix3D_H__

#pragma once

//
#include "Vector3D.h"

//
namespace Math3D {
	
	//
	class Matrix3x3
	{
	public:
		union
		{
			float	raw_data[9];
			Vector3 vector33[3];
		};
		
		Matrix3x3()
		{
			zero();
		}
		
	public:
		__inline void		zero()
		{
			raw_data[0] = 0.0f; raw_data[1] = 0.0f; raw_data[2] = 0.0f;
			raw_data[3] = 0.0f; raw_data[4] = 0.0f; raw_data[5] = 0.0f;
			raw_data[6] = 0.0f; raw_data[7] = 0.0f; raw_data[8] = 0.0f;
		}
		
		// 只能代表各个轴的缩放
		__inline void		identity()
		{
			raw_data[0] = 1.0f; raw_data[1] = 0.0f; raw_data[2] = 0.0f;
			raw_data[3] = 0.0f; raw_data[4] = 1.0f; raw_data[5] = 0.0f;
			raw_data[6] = 0.0f; raw_data[7] = 0.0f; raw_data[8] = 1.0f;
		}
	};
	
	//
	class Matrix4x4
	{
	public:
		union
		{
			float	raw_data[16];
			Vector4	vector44[4][4];
		};
		
		Matrix4x4()
		{
			zero();
		}
		
	public:
		__inline void		zero()
		{
			raw_data[ 0] = 0.0f; raw_data[ 1] = 0.0f; raw_data[ 2] = 0.0f; raw_data[ 3] = 0.0f;
			raw_data[ 4] = 0.0f; raw_data[ 5] = 0.0f; raw_data[ 6] = 0.0f; raw_data[ 7] = 0.0f;
			raw_data[ 8] = 0.0f; raw_data[ 9] = 0.0f; raw_data[10] = 0.0f; raw_data[11] = 0.0f;
			raw_data[12] = 0.0f; raw_data[13] = 0.0f; raw_data[14] = 0.0f; raw_data[15] = 0.0f;
		}
		
		__inline void		identity()
		{
			raw_data[ 0] = 1.0f; raw_data[ 1] = 0.0f; raw_data[ 2] = 0.0f; raw_data[ 3] = 0.0f;
			raw_data[ 4] = 0.0f; raw_data[ 5] = 1.0f; raw_data[ 6] = 0.0f; raw_data[ 7] = 0.0f;
			raw_data[ 8] = 0.0f; raw_data[ 9] = 0.0f; raw_data[10] = 1.0f; raw_data[11] = 0.0f;
			raw_data[12] = 0.0f; raw_data[13] = 0.0f; raw_data[14] = 0.0f; raw_data[15] = 1.0f;
		}
	};
	
}; //namespace Math3D

#endif /* __Matrix3D_H__ */
