#ifndef _CUBIC_BEZIER_H
#define _CUBIC_BEZIER_H

#include "BaseState.h"
#include <vector>
#include <assert.h>

class CubicBezier
	: public BaseState
{
public:
	CubicBezier(int width, int height);
	~CubicBezier();

	void Init();
	void Draw();
	void Update(float timeDelta, StateManager* stateMan);
	void Destroy();

private:
	std::vector<Sprite*> objectList;
	std::vector<Vector2*> curvePoints;
	float currentLERPPercent = 0.0f;

	void HandleUI(StateManager* stateMan);
	
	/*
	return a reference to Srite struct with name equal to given param if one exists, else returns nullptr.
	*/
	Sprite* GetSprite(const char* objectName);
};
#endif