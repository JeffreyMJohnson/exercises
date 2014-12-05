#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


#include "TheMath.h"
#include <crtdbg.h>
#include <iostream>


void main()
{

	Vector2* v1 = new Vector2(120, 50);
	Vector2* v2 = &(*v1 + Vector2(80, 50));

	std::cout << *v1 << std::endl;
	std::cout << *v2 << std::endl;

	//delete v1;

	_CrtDumpMemoryLeaks();

	system("pause");
}