#pragma once
#include <string>
#include <math.h>
#include "Utility.h"

class Vector3
{
public:
	float x, y, z;

	Vector3();
	Vector3(float a_x, float a_y);
	Vector3(float a_x, float a_y, float a_z);

	~Vector3();

	Vector3 operator+(const Vector3& other);
	void operator+=(const Vector3& other);

	Vector3 operator-(const Vector3& other);
	void operator-=(const Vector3& other);

	Vector3& operator=(const Vector3& other);

	Vector3& operator*(int scalar);
	void operator*=(int scalar);

	float Magnitude();

	void Normalise();

	Vector3 GetNormal();

	float DotProduct(Vector3& other);

	Vector3 CrossProduct(Vector3& other);

	/*
	returns the angle between this vector and the other given vector in radians
	*/
	float AngleBetween(Vector3& other);

	/*
	returns the angle between this vector and the other given vector in degrees
	*/
	float AngleBetweenInDegrees(Vector3& other);



	std::string ToString();

private:
	
};

