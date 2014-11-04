#include <iostream>
#include "Vector3.h"
using namespace std;

void main()
{
	Vector3 v1 = Vector3(10, 5);
	Vector3 v2 = v1.GetNormal();
	cout << "v1: " << v1.ToString();
	cout << "normalized: " << v2.ToString();
	system("pause");
}