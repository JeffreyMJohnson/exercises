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

	void HandleUI(StateManager* stateMan);
};
#endif