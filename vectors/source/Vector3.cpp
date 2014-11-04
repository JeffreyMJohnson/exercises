#include "..\include\Vector3.h"


Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
	z = 0;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	Vector3(a_x, a_y);
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return temp;
}

void Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return temp;
}

void Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = 0;
	return *this;
}

Vector3& Vector3::operator*(int scalar)
{
	Vector3 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	return temp;
}

float Vector3::Magnitude()
{
	return (sqrtf((powf(x, 2.0f) + powf(y, 2.0f))));
}

void Vector3::Normalise()
{
	float length = Magnitude();

	if (length == 0)
	{
		return;
	}

	x = x / length;
	y = y / length;
}

Vector3 Vector3::GetNormal()
{
	Vector3 temp = *this;
	temp.Normalise();
	return temp;
}

std::string Vector3::ToString()
{
	char result[128];
	std::sprintf(result, "Vector3 [x: %f y: %f z: %f]\n", x, y, z);
	return std::string(result);
}
