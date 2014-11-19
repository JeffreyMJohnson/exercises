#include <iostream>
#include "Vector3.h"
using namespace std;

void main()
{
	Vector3 v1 = Vector3(0, 10);
	Vector3 v2 = Vector3(0, -10);
	Vector3 xProduct = v1.CrossProduct(v2);

	cout << "v1: " << v1.ToString();
	cout << "v2: " << v2.ToString();
	cout << "XProduct : " << xProduct.ToString();

	float angle = v1.AngleBetween(v2);
	float angleDegrees = v1.AngleBetweenInDegrees(v2);

	cout << "angle between radians: " << angle << endl;
	cout << "angle between degrees: " << angleDegrees<< endl;
	system("pause");
}