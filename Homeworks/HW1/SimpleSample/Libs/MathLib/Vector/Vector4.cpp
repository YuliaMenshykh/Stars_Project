#include "Mpch.h"

#include "Vector4.h"
#include "Vector3.h"
#include "Matrix/Matrix.h"

Vector4::Vector4()
	: x( 0.0f )
	, y( 0.0f )
	, z( 0.0f )
	, w( 0.0f )
{
}
Vector4::Vector4( float _x, float _y, float _z )
	: x( _x )
	, y( _y )
	, z( _z )
	, w( 1.0f )
{
}
Vector4::Vector4( float _x, float _y, float _z, float _w )
	: x( _x )
	, y( _y )
	, z( _z )
	, w( _w )
{
}
Vector4::Vector4( const Vector3& vector )
	: x( vector.x )
	, y( vector.y )
	, z( vector.z )
	, w( 1.0f )
{
}
Vector4::Vector4( const Vector3& vector, float _w )
	: x( vector.x )
	, y( vector.y )
	, z( vector.z )
	, w( _w )
{
}

// copy and assigment
//
Vector4::Vector4( const Vector4& vector )
	: x( vector.x )
	, y( vector.y )
	, z( vector.z )
	, w( vector.w )
{
}

Vector4& Vector4::operator=( const Vector4& vector )
{
	if( this != &vector )
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
		w = vector.w;
	}
	return *this;
}

Vector4 Vector4::operator+( const Vector4& vector )const
{
	return Vector4( x + vector.x, y + vector.y, z + vector.z, w + vector.w );
}

Vector4& Vector4::operator+=( const Vector4& vector )
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;

	return *this;
}

Vector4 Vector4::operator-()const
{
	return Vector4( -x, -y, -z, -w );
}

Vector4 Vector4::operator-( const Vector4& vector )const
{
	return Vector4( x - vector.x, y - vector.y, z - vector.z, w - vector.w );
}

Vector4& Vector4::operator-=( const Vector4& vector )
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;

	return *this;
}

Vector4 Vector4::operator*( float k )const
{
	return Vector4( x * k, y * k, z * k, w * k );
}

Vector4& Vector4::operator*=( float k )
{
	x *= k;
	y *= k;
	z *= k;
	w *= k;

	return *this;
}

Vector4 Vector4::operator/( float k )const
{
	float kInv = 1.0f / k;
	return Vector4( x * kInv, y * kInv, z * kInv, w * kInv );
}

Vector4& Vector4::operator/=( float k )
{
	return operator *= ( 1.0f / k );
}

float Vector4::Length()const
{
	return sqrtf( x * x + y * y + z * z + w * w );
}

Vector4& Vector4::Normalize()
{
	float lenInv = 1.0f / Length();
	x *= lenInv;
	y *= lenInv;
	z *= lenInv;
	w *= lenInv;

	return *this;
}

Vector4 Vector4::Modulate( const Vector4& vector )const
{
	return Vector4( x * vector.x, y * vector.y, z * vector.z, w * vector.w );
}

float Vector4::Dot( const Vector4& vector )const
{
	return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
}

Vector4 Vector4::operator * ( const Matrix& m )const
{
	Vector4 res;
	res.x = x * m.m[ 0 ][ 0 ] + y * m.m[ 1 ][ 0 ] + z * m.m[ 2 ][ 0 ] + w * m.m[ 3 ][ 0 ];
	res.y = x * m.m[ 0 ][ 1 ] + y * m.m[ 1 ][ 1 ] + z * m.m[ 2 ][ 1 ] + w * m.m[ 3 ][ 1 ];
	res.z = x * m.m[ 0 ][ 2 ] + y * m.m[ 1 ][ 2 ] + z * m.m[ 2 ][ 2 ] + w * m.m[ 3 ][ 2 ];
	res.w = x * m.m[ 0 ][ 3 ] + y * m.m[ 1 ][ 3 ] + z * m.m[ 2 ][ 3 ] + w * m.m[ 3 ][ 3 ];

	return res;
}

float& Vector4::operator[]( unsigned int idx )
{
	return ( &x )[ idx ];
}

const float& Vector4::operator[]( unsigned int idx )const
{
	return ( &x )[ idx ];
}