#include "Singleton.h"
#include <iostream>

using namespace std;

Singleton* s = Singleton::GetInstance();
int w = s->screenWidth;
int h = s->screenHeight;

void main()
{
	cout << "width: " << w;
	system("pause");
}