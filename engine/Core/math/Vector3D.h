//
//  Vector3D.h
//
//
//  Created by enos sariel on 16/4/1.
//  Copyright © 2016年 enos sariel. All rights reserved.
//

#ifndef __Vector3D_H__
#define __Vector3D_H__

#pragma once

//
#include <math.h>

//
namespace Math3D {
	
	//
	class Vector2
	{
	public:
		union
		{
			float	raw_data[2];
			struct
			{
				float x;
				float y;
			};
		};
		
		Vector2(float _x = 0.0f, float _y = 0.0f)
		{
			x	= _x;
			y	= _y;
		}
		
		Vector2(const Vector2& v)
		{
			x	= v.x;
			y	= v.y;
		}
		
		Vector2(const Vector2* v)
		{
			x	= v->x;
			y	= v->y;
		}
		
		const static Vector2		ZERO;
		const static Vector2		AXIS_X;
		const static Vector2		AXIS_Y;
		
	public:
		Vector2		operator + (const Vector2& v)
		{
			return Vector2(x+v.x, y+v.y);
		}
		Vector2		operator - (const Vector2& v)
		{
			return Vector2(x-v.x, y-v.y);
		}
		void		operator += (const Vector2& v)
		{
			x += v.x; y += v.y;
		}
		void		operator -= (const Vector2& v)
		{
			x -= v.x, y -= v.y;
		}
		
	public:
		__inline float	length()
		{
			return sqrt((x*x) + (y*y));
		}
		__inline float	distance(const Vector2& v)
		{
			return sqrt(((x-v.x)*(x-v.x)) + ((y-v.y)*(y-v.y)));
		}
		__inline float	dotProduct(const Vector2& v)
		{
			return (x*v.x) + (y*v.y);
		}
	};
	
	//
	class Vector3
	{
	public:
		union
		{
			float	raw_data[3];
			struct
			{
				float x;
				float y;
				float z;
			};
		};
		
		Vector3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
		{
			x	= _x;
			y	= _y;
			z	= _z;
		}
		
		Vector3(const Vector2& v)
		{
			x	= v.x;
			y	= v.y;
			z	= 0.0f;
		}
		
		Vector3(const Vector2* v)
		{
			x	= v->x;
			y	= v->y;
			z	= 0.0f;
		}
		Vector3(const Vector3& v)
		{
			x	= v.x;
			y	= v.y;
			z	= v.z;
		}
		
		Vector3(const Vector3* v)
		{
			x	= v->x;
			y	= v->y;
			z	= v->z;
		}
		
		const static Vector3		ZERO;
		const static Vector3		AXIS_X;
		const static Vector3		AXIS_Y;
		const static Vector3		AXIS_Z;
		
	public:
		Vector3		operator + (const Vector3& v)
		{
			return Vector3(x+v.x, y+v.y, z+v.z);
		}
		Vector3		operator - (const Vector3& v)
		{
			return Vector3(x-v.x, y-v.y, z-v.z);
		}
		void		operator += (const Vector3& v)
		{
			x += v.x; y += v.y; z += v.z;
		}
		void		operator -= (const Vector3& v)
		{
			x -= v.x, y -= v.y; z -= v.z;
		}
		
	public:
		__inline float	length()
		{
			return sqrt((x*x) + (y*y) + (z*z));
		}
		__inline float	distance(const Vector3& v)
		{
			return sqrt(((x-v.x)*(x-v.x)) + ((y-v.y)*(y-v.y)) + ((z-v.z)*(z-v.z)));
		}
		__inline float	normalize()
		{
			float l = this->length();
			x /= l;
			y /= l;
			z /= l;
			return l;
		}
		__inline float	dotProduct(const Vector3& v)
		{
			return (x*v.x) + (y*v.y) + (z*v.z);
		}
		__inline Vector3	crossProduct(const Vector3& v)
		{
			return Vector3((y*v.z) - (z*v.y),
						   (z*v.x) - (x*v.z),
						   (x*v.y) - (y*v.x));
		}
	};
	
	//
	class Vector4
	{
	public:
		union
		{
			float	raw_data[4];
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
		};
		
		Vector4(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f, float _w = 0.0f)
		{
			x	= _x;
			y	= _y;
			z	= _z;
			w	= _w;
		}
		
		Vector4(const Vector2& v)
		{
			x	= v.x;
			y	= v.y;
			z	= 0.0f;
			w	= 0.0f;
		}
		
		Vector4(const Vector2* v)
		{
			x	= v->x;
			y	= v->y;
			z	= 0.0f;
			w	= 0.0f;
		}
		Vector4(const Vector3& v)
		{
			x	= v.x;
			y	= v.y;
			z	= v.z;
			w	= 0.0f;
		}
		
		Vector4(const Vector3* v)
		{
			x	= v->x;
			y	= v->y;
			z	= v->z;
			w	= 0.0f;
		}
		Vector4(const Vector4& v)
		{
			x	= v.x;
			y	= v.y;
			z	= v.z;
			w	= v.w;
		}
		
		Vector4(const Vector4* v)
		{
			x	= v->x;
			y	= v->y;
			z	= v->z;
			w	= v->w;
		}
		
		const static Vector4		ZERO;
		const static Vector4		IDENTITY; //Identity
		
	public:
		__inline float	length()
		{
			return sqrt((x*x) + (y*y) + (z*z) + (w*w));
		}
		__inline float	normalize()
		{
			float l = this->length();
			x /= l;
			y /= l;
			z /= l;
			w /= l;
			return l;
		}
	};
	
	//
	class Colour	:	public Vector4
	{
	public:
		Colour(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
			: Vector4(r, g, b, a)
		{ }
		
		float		red() { return x; }
		float		green() { return y; }
		float		blue() { return z; }
		float		alpha() { return w; }
		
		const static Colour BLACK;
		const static Colour WHITE;
		const static Colour RED;
		const static Colour GREEN;
		const static Colour BLUE;
		const static Colour GRAY;
		const static Colour PURPLE;
		const static Colour CYAN;
		const static Colour YELLOW;
	};
	
}; //namespace Math3D

#endif /* __Vector3D_H__ */
