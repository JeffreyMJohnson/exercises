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
	void HandleUI(StateManager* stateMan);
	
};
#endif