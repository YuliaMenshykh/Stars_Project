#pragma once

class Vector3
{
public:
	// default {ctor}
	//
	Vector3();
	Vector3( float _x, float _y, float _z );

	// copy and assigment
	//
	Vector3( const Vector3& vector );
	Vector3 & operator=(const Vector3& vector);
	
	//Vector's operators
	//
	Vector3 operator+( const Vector3& vector )const;
	Vector3& operator+=( const Vector3& vector );
	Vector3 operator-()const;
	Vector3 operator-( const Vector3& vector )const;
	Vector3& operator-=( const Vector3& vector );
	Vector3 operator*( float k )const;
	Vector3& operator *=( float k );
	Vector3 operator/( float k )const;
	Vector3& operator/=( float k );
	

	float Length()const;
	Vector3& Normalize();

	Vector3 Modulate( const Vector3& vector )const;
	float Dot( const Vector3& vector )const;
	Vector3 Cross( const Vector3& vector )const;

	//access to elements
	float& operator [] ( unsigned int idx );
	const float& operator [] ( unsigned int idx )const;

public:

	float x;
	float y;
	float z;
};
