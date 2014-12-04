#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

Singleton::Singleton(){};
Singleton::~Singleton(){};

Singleton* Singleton::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Singleton();
	}
	return instance;
}