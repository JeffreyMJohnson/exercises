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
	void HandleUI(StateManager* stateMan);
};


#endif