//
//  Matrix3D.cpp
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/3.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#include "Matrix3D.h"


//
namespace Math3D {
	
	//
	const Matrix3x3	Matrix3x3::ZERO		=
	{
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};
	
	const Matrix3x3	Matrix3x3::IDENTITY	=
	{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};
	
	//
	const Matrix4x4	Matrix4x4::ZERO		=
	{
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	};
	
	const Matrix4x4	Matrix4x4::IDENTITY	=
	{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	
	
}; //namespace Math3D