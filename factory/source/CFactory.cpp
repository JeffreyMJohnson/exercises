#include "CFactory.h"
#include <cstring>

//CFactory g_Factory;

CFactory::CFactory(void)
{
	memset(makeFunctions, 0, sizeof(makeFunctions));
}

CFactory* CFactory::instance = nullptr;

CFactory* CFactory::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new CFactory;
	}
	return instance;
}

CFactory::~CFactory(void)
{
}


IObject* CFactory::CreateObject(const char* name)
{
	for(int i = 0; i < 256; i++)
	{
		if (makeFunctions[i].MakeFunction != 0)
		{
			if ( strcmp(name, makeFunctions[i].name) == 0 )
			{
				IObject* obj = makeFunctions[i].MakeFunction();
				obj->SetTypeName(name);
				return obj;
			}
		}
		else
			return 0;
	}
}


void CFactory::AddMakeFunction(const char* name, CFactory::TMakeFunction func)
{
	for(int i = 0; i < 256; i++)
	{
		if (makeFunctions[i].MakeFunction == 0)
		{
			strcpy(makeFunctions[i].name, name);
			makeFunctions[i].MakeFunction = func;
			return;
		}
	}
}