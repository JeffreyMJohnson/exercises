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
	x = a_x;
	y = a_x;
	z = a_z;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	temp.z += other.z;
	return temp;
}

void Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	temp.z -= other.z;
	return temp;
}

void Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3& Vector3::operator*(int scalar)
{
	Vector3 temp = *this;
	temp.x *= scalar;
	temp.y *= scalar;
	temp.z *= scalar;
	return temp;
}

void Vector3::operator*=(int scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

float Vector3::Magnitude()
{
	return (sqrtf((powf(x, 2.0f) + powf(y, 2.0f) + pow(z, 2))));
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
	z = z / length;
}

Vector3 Vector3::GetNormal()
{
	Vector3 temp = *this;
	temp.Normalise();
	return temp;
}

float Vector3::DotProduct(Vector3& other)
{
	return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3 Vector3::CrossProduct(Vector3& other)
{
	return Vector3((y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x));
}

/*
returns the angle between this vector and the other given vector in radians
*/
float Vector3::AngleBetween(Vector3& other)
{
	//angle between this and other = arccos(THIS.OTHER) (dot product)
	Vector3 temp = GetNormal();
	return acosf(temp.DotProduct(other.GetNormal()));
}

/*
returns the angle between this vector and the other given vector in degrees
*/
float Vector3::AngleBetweenInDegrees(Vector3& other)
{
	//angle between this and other = arccos(THIS.OTHER) (dot product)
	Vector3 temp = GetNormal();
	return Helper::RadiansToDegrees(acosf(temp.DotProduct(other.GetNormal())));
}

std::string Vector3::ToString()
{
	char result[128];
	std::sprintf(result, "Vector3 [x: %f y: %f z: %f]\n", x, y, z);
	return std::string(result);
}
