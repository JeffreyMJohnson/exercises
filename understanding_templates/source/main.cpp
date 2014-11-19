#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
For each of the following functions, implement both a non-templated and templated version of each, and write any specialized template definitions as required:

max – returns the maximum of 2 numbers passed into it
min – returns the minimum of 2 numbers passed into it

clamp – clamps a number between 2 passed in values
abs – removes the ‘-‘ sign from a number if it has it
lerp – Linear Interpolation, returns a number between 2 values based on a float.
*/

float& Max(float& first, float& second)
{
	if (first > second)
		return first;
	else
		return second;
}

int& Min(int& first, int& second)
{
	if (first < second)
		return first;
	else
		return second;
}

template<typename T>
T& Min(T& first, T& second)
{
	if (first < second)
		return first;
	else
		return second;
}

template<typename T>
T& Max(T& first, T& second)
{
	if (first > second)
		return first;
	else
		return second;
}

int& Clamp(int x, const int& min, const int& max)
{
	if (x > min && x < max)
		return x;
	if (x < min)
	{
		x = min;
		return x;
	}
	if (x > max)
	{
		x = max;
		return x;
	}
}

template<typename T>
void Clamp(T& x, const T& min, const T& max)
{
	if (x > min && x < max)
		//return x;
		return;
	if (x < min)
	{
		x = min;
	}
	if (x > max)
	{
		x = max;
	}
}

int& ABS(int& x)
{
	if (x < 0)
		x *= -1;
	return x;
}

template<typename T>
T& ABS(T& x)
{
	if (x < 0)
		x *= -1;
	return x;
}

void main()
{



	int i1 = 10;
	int i2 = 5;
	float f1 = 1.5;
	float f2 = 25.345;

	cout << "Max(" << f1 << ", " << f2 << ") = " << Max(f1, f2) << endl;
	cout << "Max(" << f1 << ", " << f2 << ") = " << Max<float>(f1, f2) << endl;
	cout << "Max(" << i1 << ", " << i2 << ") = " << Max<int>(i1, i2) << endl;

	cout << "Min(" << f1 << ", " << f2 << ") = " << Min(f1, f2) << endl;
	cout << "Min(" << f1 << ", " << f2 << ") = " << Min<float>(f1, f2) << endl;
	cout << "Min(" << i1 << ", " << i2 << ") = " << Min<int>(i1, i2) << endl;
	Clamp(i1, 0, 5);
	cout << i1 << " clamped to 5 = " << i1 << endl;
	i1 = 10;
	Clamp<int>(i1, 0, 5);
	cout << i1 << " clamped to 5 = " << i2 << endl;

	int i3 = -10;
	int i4 = 100;
	cout << "ABS(" << i3 << ") = ";
	cout << ABS(i3) << endl;
	cout << "ABS(" << i4 << ") = ";
	cout << ABS(i4) << endl;

	i3 = -10;
	i4 = 100;
	float f3 = -3.14159f;
	float f4 = 3.14159f;
	cout << "ABS<int>(" << i3 << ") = ";
	cout << ABS<int>(i3) << endl;
	cout << "ABS<int>(" << i4 << ") = ";
	cout << ABS<int>(i4) << endl;
	cout << "ABS<float>(" << f3 << ") = ";
	cout << ABS<float>(f3) << endl;
	cout << "ABS<int>(" << i4 << ") = ";
	cout << ABS<int>(i4) << endl;
	system("pause");
}