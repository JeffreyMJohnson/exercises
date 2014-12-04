#include "CLevel.h"
#include "CFactory.h"
#include "string_Util.h"
//#include "CPlayer.h"

CLevel::CLevel(void)
{
	memset(objects, 0, sizeof(objects));
}

CLevel::~CLevel(void)
{
}

void CLevel::LoadLevel(const char* filename)
{
	FILE* file = fopen(filename, "r");

	while(!feof(file))
	{
		char line[256];

		fgets(line, 256, file);
		trimWhiteSpace(line);

		//IObject* obj = g_Factory.CreateObject(line);
		IObject* obj = CFactory::GetInstance()->CreateObject(line);
		
		obj->Load(file);
		this->Insert(obj);
	}

	fclose(file);
}

void CLevel::SaveLevel(const char* filename)
{
	FILE* file = fopen(filename, "w");

	for(int i = 0; i < 256; i++)
	{
		if (objects[i] == 0 )
		{
			break; 
		}

		fprintf(file, "%s\n", objects[i]->GetTypeName());
		objects[i]->Save(file);
	}

	fclose(file);
}


void CLevel::Insert(IObject* obj)
{
	for(int i = 0; i < 256; i++)
	{
		if (objects[i] == 0 )
		{
			objects[i] = obj;
			return;
		}
	}
}


void CLevel::Update(float dt)
{
	for(int i = 0; i < 256; i++)
	{
		if (objects[i] == 0 )
		 return;

		objects[i]->Update(dt);
	}
}


void CLevel::Draw()
{
	for(int i = 0; i < 256; i++)
	{
		if (objects[i] == 0 )
		 return;

		objects[i]->Draw();
	}
}