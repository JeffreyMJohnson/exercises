#include "CSprite.h"
#include <cstdlib>

CSprite::CSprite(void)
{
	Texture = rand();
}

CSprite::~CSprite(void)
{
}

void CSprite::Load(FILE* file)
{
	//Call the base class load first
	IObject::Load(file);

	fscanf(file, "%i\n", &Texture);
}

void CSprite::Save(FILE* file)
{
	//Call the base class save first
	IObject::Save(file);

	fprintf(file, "%i\n", Texture);
}
