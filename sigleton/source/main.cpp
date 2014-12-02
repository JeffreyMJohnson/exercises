#include "Singleton.h"
#include <ostream>

using namespace std;

Singleton* s = Singleton::GetInstance();
int w = s->screenWidth;
int h = s->screenHeight;

void main()
{
	
}