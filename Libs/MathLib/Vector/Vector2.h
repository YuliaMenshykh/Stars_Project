#pragma once


class Vector2
{
public:
	// default ctor
	//
	Vector2();
	Vector2( float _x, float _y );

	// copy and assigment
	//
	Vector2( const Vector2& vector );
	Vector2 & operator= (const Vector2& vector);


	//Vector's operators
	//
	Vector2 operator+ ( const Vector2& vector )const;
	Vector2& operator+= ( const Vector2& vector );
	Vector2 operator-()const;
	Vector2 operator-( const Vector2& vector )const;
	Vector2& operator-=( const Vector2& vector );
	Vector2 operator*( float k )const;
	Vector2& operator*=( float k );
	Vector2 operator/( float k )const;
	Vector2& operator/=( float k );

	// getter lengh of vector
	//
	float Length()const;

	// normalizing itself
	//
	Vector2& Normalize();

	// modulate vector by values
	//
	Vector2 Modulate( const Vector2& vector )const;

	float Dot(const Vector2& vector)const;

	//access to elements
	//
	float& operator [] (unsigned int idx);
	const float& operator [] (unsigned int idx)const;

public:
	float x;
	float y;
};