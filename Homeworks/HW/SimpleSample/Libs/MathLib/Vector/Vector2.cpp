#include "Mpch.h"
#include "Vector2.h"


Vector2::Vector2()
	: x( 0.0f )
	, y( 0.0f )
{
}
Vector2::Vector2( float _x, float _y )
	: x( _x )
	, y( _y )
{
}
Vector2::Vector2( const Vector2& vector )
	: x( vector.x )
	, y( vector.y )
{
}

Vector2& Vector2::operator=( const Vector2& other )
{
	if( this != &other )
	{
		x = other.x;
		y = other.y;
	}

	return *this;
}



Vector2 Vector2::operator+( const Vector2& vector )const
{
	return Vector2( x + vector.x, y + vector.y );
}

Vector2& Vector2::operator+=( const Vector2& vector )
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector2 Vector2::operator-()const
{
	return Vector2( -x, -y );
}

Vector2 Vector2::operator-( const Vector2& vector )const
{
	return Vector2( x - vector.x, y - vector.y );
}

Vector2& Vector2::operator-=( const Vector2& vector )
{
	x -= vector.x;
	y -= vector.y;

	return *this;
}

Vector2 Vector2::operator*( float k )const
{
	return Vector2( x * k, y * k );
}

Vector2& Vector2::operator*=( float k )
{
	x *= k;
	y *= k;

	return *this;
}

Vector2 Vector2::operator/( float k )const
{
	float kInv = 1.0f / k;
	return Vector2( x * kInv, y * kInv );
}

Vector2& Vector2::operator/=( float k )
{
	return operator*= ( 1.0f / k );
}


float& Vector2::operator[] ( unsigned int idx )
{
	return ( &x )[ idx ];
}

const float& Vector2::operator[] ( unsigned int idx )const
{
	return ( &x )[ idx ];
}

float Vector2::Length()const
{
	return sqrtf( x * x + y * y );
}

Vector2& Vector2::Normalize()
{
	float lenInv = 1.0f / Length();
	x *= lenInv;
	y *= lenInv;

	return *this;
}

Vector2 Vector2::Modulate( const Vector2& vector )const
{
	return Vector2( x * vector.x, y * vector.y );
}

float Vector2::Dot( const Vector2& vector )const
{
	return x * vector.x + y * vector.y;
}
