#pragma once
#include <string>
#include <math.h>

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

	float Magnitude();

	void Normalise();

	Vector3 GetNormal();

	std::string ToString();

private:
	
};

