#include "CPlayer.h"
#include "string_Util.h"

CPlayer::CPlayer(void)
{
}

CPlayer::~CPlayer(void)
{
}

void CPlayer::Update(float dt)
{ 
	printf("Player update!\n");
	Position.x += 100;
}

void CPlayer::Load(FILE* file)
{
	//Call the base class load first
	IObject::Load(file);
	fgets(Name, 256, file);
	trimWhiteSpace(Name);
}

void CPlayer::Save(FILE* file)
{
	//Call the base class save first
	IObject::Save(file);
	fprintf(file, "%s\n", Name);
}
