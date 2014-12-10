#ifndef _BASE_STATE_H_
#define _BASE_STATE_H_

#include "AIE.h"
#include "..\..\..\JMath\JMath_Library\JMath_static\include\TheMath.h"
#include "StateManager.h"
#include <vector>

typedef unsigned int uInt;

class StateManager;

struct Sprite
{
	Vector2 size;
	Vector2 position;
	uInt ID = 0;
	char* name = "";

	bool IsCollided(const Vector2& pos)
	{
		Vector2 dX = position - pos;
		dX.x = abs(dX.x);
		dX.y = abs(dX.y);
		return dX.x <= size.x;
	}
};

struct Player
	: public Sprite
{
	bool flipDirection = false;
};



class BaseState
{
public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update(float timeDelta, StateManager* stateMan) = 0;
	virtual void Destroy() = 0;

	const char* spriteFileName = "./images/crate_sideup.png";

protected:
	int screenWidth;
	int screenHeight;

	std::vector<Sprite*> objectList;
	std::vector<Vector2*> curvePoints;
	float currentLERPPercent = 0.0f;



	Sprite* GetSprite(char* a_name)
	{
		for (std::vector<Sprite*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
		{
			if ((*it)->name == a_name)
			{
				return *it;
			}
		}
		return nullptr;
	}
};



#endif