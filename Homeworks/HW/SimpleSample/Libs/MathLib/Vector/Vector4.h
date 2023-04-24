#pragma once

class Vector3;
class Matrix;

class Vector4
{
public:
	// default {ctor} and variations
	//
	Vector4();
	Vector4( float _x, float _y, float _z );
	Vector4( float _x, float _y, float _z, float _w );
	Vector4( const Vector3& vector );
	Vector4( const Vector3& vector, float _w );

	// copy and assigment
	//
	Vector4( const Vector4& vector );
	Vector4 & operator = (const Vector4& vector);

	//Vector's operators
	//
	Vector4 operator+(const Vector4& vector)const;
	Vector4 & operator+=( const Vector4& vector);
	Vector4 operator-()const;
	Vector4 operator-( const Vector4& vector)const;
	Vector4 & operator-=( const Vector4& vector);
	Vector4 operator*(float k)const;
	Vector4 & operator*=(float k);
	Vector4 operator/(float k)const;
	Vector4 & operator/=(float k);
	
	float Length()const;
	Vector4 & Normalize();
	Vector4 Modulate( const Vector4& vector)const;
	float Dot(const Vector4& vector)const;

	//matrix multiplication
	//
	Vector4 operator* ( const Matrix& m )const;

	//access to elements
	float& operator[](unsigned int idx);
	const float& operator[](unsigned int idx)const;

public:
	//data members
	float x;
	float y;
	float z;
	float w;
};

