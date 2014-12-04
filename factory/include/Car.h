#ifndef _CAR_H_
#define _CAR_H_
#include "CSprite.h"

class Car
	: public CSprite
{
public:
	Car();
	~Car();

	void Load(FILE* file);
	void Save(FILE* file);

	void Update(float dt) { printf("Car update!\n"); }
	void Draw();


private:
	int enginePower;
	int velocity;
	char occupied[256];
};

MAKEFUNCTION(Car)
#endif