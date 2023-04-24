#pragma once


class Vector3;
class Vector4;

class Matrix
{
public:
	//Default {ctor}
	//
	Matrix();
	Matrix(float val);

	Matrix(const Matrix& mat);
	Matrix& operator=(const Matrix& mat);

	// Matrix operations
	Matrix& SetZero();
	Matrix& SetIdentity();

	Matrix& SetRotationX(float angle);
	Matrix& SetRotationY(float angle);
	Matrix& SetRotationZ(float angle);
	Matrix& SetRotationAngleAxis(float angle, float x, float y, float z);

	Matrix& SetScale(float scale);
	Matrix& SetScale(float scaleX, float scaleY, float scaleZ);
	Matrix& SetScale(const Vector3& scaleVec);

	Matrix& SetTranslation(float x, float y, float z);
	Matrix& SetTranslation(const Vector3& vec);

	Matrix& SetPerspective(float fovY, float aspect, float nearPlane, float farPlane);
	Matrix& SetOrtho(float l, float r, float b, float t, float zn, float zf);

	Matrix Transpose()const;

	Matrix operator + (const Matrix& mat)const;
	Matrix& operator += (const Matrix& mat);
	Matrix operator - (const Matrix& mat)const;
	Matrix& operator -= (const Matrix& mat);

	Matrix operator * (const Matrix& mat)const;
	Matrix operator * (float k)const;
	Matrix& operator *= (float k);

	Vector4 operator * (const Vector4& vec);



public:
	//data members
	//
	float m[4][4];
};

