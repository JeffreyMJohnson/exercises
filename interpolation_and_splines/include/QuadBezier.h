#ifndef _QUAD_BEZIER_H
#define _QUAD_BEZIER_H

#include "BaseState.h"
#include <vector>

class QuadBezier
	: public BaseState
{
public:
	QuadBezier(int width, int height);
	~QuadBezier();

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