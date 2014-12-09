#ifndef HERMITE_SPLINE_H_
#define HERMITE_SPLINE_H_

#include "BaseState.h"
#include <vector>
#include <assert.h>

class HermiteSpline
	: public BaseState
{
public:
	HermiteSpline(int width, int height);
	~HermiteSpline();

	void Init();
	void Update(float timeDelta, StateManager* stateMan);
	void Draw();
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