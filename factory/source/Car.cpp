#include "Car.h"

Car::Car()
{
	Texture = rand();
}

Car::~Car()
{
}

void Car::Load(FILE* file)
{

	CSprite::Load(file);

	fscanf(file, "%i\n", &enginePower);
	fscanf(file, "%i\n", &velocity);
	fscanf(file, "%s\n", &occupied);
}

void Car::Draw()
{
	{
		printf("Drawing a Car: %i\n", Texture);
		printf("Engine Power: %i\n", enginePower);
		printf("velocity: %i\n", velocity);
		printf("Occupied: %s\n", occupied);
	}
}

void Car::Save(FILE* file)
{
	//Call the base class save first
	CSprite::Save(file);

	fprintf(file, "%i\n", enginePower);
	fprintf(file, "%i\n", velocity);
	fprintf(file, "%s\n", occupied);
}