#include "IObject.h"

IObject::IObject(void)
{
}

IObject::~IObject(void)
{
}


//Load save functions for this type
void IObject::Load(FILE* file)
{
	fscanf(file, "%i\n", &this->ID);
	fscanf(file, "%f, %f\n", &this->Position.x, &this->Position.y);
	fscanf(file, "%f, %f\n", &this->Size.x, &this->Size.y);
	fscanf(file, "%f\n", &this->Rotation);
}

void IObject::Save(FILE* file)
{
	//Write the attributes
	fprintf(file, "%i\n", this->ID);
	fprintf(file, "%f, %f\n", this->Position.x, this->Position.y);
	fprintf(file, "%f, %f\n", this->Size.x, this->Size.y);
	fprintf(file, "%f\n", this->Rotation);
}