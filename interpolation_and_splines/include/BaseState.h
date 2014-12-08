#ifndef _BASE_STATE_H_
#define _BASE_STATE_H_

#include "AIE.h"
#include "..\..\..\JMath\JMath_Library\JMath_static\include\TheMath.h"
#include "StateManager.h"

typedef unsigned int uInt;

class StateManager;

struct Sprite
{
	Vector2 size;
	Vector2 position;
	uInt ID = 0;
	char* name = "";
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
};



#endif