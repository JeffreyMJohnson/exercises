#ifndef _LERP_STATE_H
#define _LERP_STATE_H	

#include "BaseState.h"
#include <vector>
#include <iostream>

class LERPState
	: public BaseState
{
public:
	LERPState(int width, int height);
	~LERPState();

	void Init();
	void Draw();
	void Update(float timeDelta, StateManager* stateMan);
	void Destroy();

private:
	std::vector<Sprite*> objectList;
	std::vector<Vector2*> curvePoints;
	float currentLERPPercent = 0.0f;

	void HandleUI(StateManager* stateMan);
};
#endif