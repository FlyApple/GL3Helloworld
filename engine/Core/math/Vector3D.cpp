//
//  Vector3D.cpp
//  GL3Helloworld
//
//  Created by enos sariel on 16/4/1.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#include "Vector3D.h"

//
namespace Math3D {
	
	//
	const Vector2	Vector2::ZERO		= Vector2(0.0f, 0.0f);
	const Vector2	Vector2::AXIS_X		= Vector2(1.0f, 0.0f);
	const Vector2	Vector2::AXIS_Y		= Vector2(0.0f, 1.0f);

	//
	const Vector3	Vector3::ZERO		= Vector3(0.0f, 0.0f, 0.0f);
	const Vector3	Vector3::AXIS_X		= Vector3(1.0f, 0.0f, 0.0f);
	const Vector3	Vector3::AXIS_Y		= Vector3(0.0f, 1.0f, 0.0f);
	const Vector3	Vector3::AXIS_Z		= Vector3(0.0f, 0.0f, 1.0f);
	
	//
	const Vector4	Vector4::ZERO		= Vector4(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4	Vector4::IDENTITY	= Vector4(0.0f, 0.0f, 0.0f, 1.0f);
	
	//
	const Colour	Colour::BLACK		= Colour(0.0, 0.0, 0.0);
	const Colour	Colour::WHITE		= Colour(1.0, 1.0, 1.0);
	const Colour	Colour::RED			= Colour(1.0, 0.0, 0.0);
	const Colour	Colour::GREEN		= Colour(0.0, 1.0, 0.0);
	const Colour	Colour::BLUE		= Colour(0.0, 0.0, 1.0);
	const Colour	Colour::GRAY		= Colour(0.5, 0.5, 0.5);
	const Colour	Colour::PURPLE		= Colour(1.0, 0.0, 1.0);
	const Colour	Colour::CYAN		= Colour(0.0, 1.0, 1.0);
	const Colour	Colour::YELLOW		= Colour(1.0, 1.0, 0.0);
	
	
}; //namespace Math3D