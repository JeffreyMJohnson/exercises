#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "BaseState.h"
#include "LERPState.h"
#include "QuadBezier.h"
#include <iostream>

class MenuState
	: public BaseState
{
public:
	MenuState(int width, int height);
	~MenuState();

	void Init();
	void Update(float timeDelta, StateManager* stateMan);
	void Draw();
	void Destroy();

private:
	float midScreenWidth;
	float midScreenHeight;

	void HandleUI(StateManager* stateMan);
};

#endif