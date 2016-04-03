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
namespace Math3D {
	
	//
	class Matrix3x3
	{
	public:
		union
		{
			float	raw_data[9];
			float	raw_array[3][3];
		};
		
		Matrix3x3()
		{
			zero();
		}
		
		Matrix3x3(const Matrix3x3& m)
		{
			for(int i = 0; i < 9; i ++)
			{ raw_data[i] = m.raw_data[i]; }
		}
		
		Matrix3x3(float data00, float data01, float data02,
				  float data03, float data04, float data05,
				  float data06, float data07, float data08)
		{
			raw_data[ 0] = data00; raw_data[ 1] = data01; raw_data[ 2] = data02;
			raw_data[ 3] = data03; raw_data[ 4] = data04; raw_data[ 5] = data05;
			raw_data[ 6] = data06; raw_data[ 7] = data07; raw_data[ 8] = data08;
		}
		
		//
		const static Matrix3x3		ZERO;
		const static Matrix3x3		IDENTITY; //Identity
		
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
			float	raw_array[4][4];
		};
		
		Matrix4x4()
		{
			zero();
		}
		
		Matrix4x4(const Matrix4x4& m)
		{
			for(int i = 0; i < 16; i ++)
			{ raw_data[i] = m.raw_data[i]; }
		}
		
		Matrix4x4(float data00, float data01, float data02, float data03,
				  float data04, float data05, float data06, float data07,
				  float data08, float data09, float data10, float data11,
				  float data12, float data13, float data14, float data15)
		{
			raw_data[ 0] = data00; raw_data[ 1] = data01; raw_data[ 2] = data02; raw_data[ 3] = data03;
			raw_data[ 4] = data04; raw_data[ 5] = data05; raw_data[ 6] = data06; raw_data[ 7] = data07;
			raw_data[ 8] = data08; raw_data[ 9] = data09; raw_data[10] = data10; raw_data[11] = data11;
			raw_data[12] = data12; raw_data[13] = data13; raw_data[14] = data14; raw_data[15] = data15;
		}
		
		//
		const static Matrix4x4		ZERO;
		const static Matrix4x4		IDENTITY; //Identity
		
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
