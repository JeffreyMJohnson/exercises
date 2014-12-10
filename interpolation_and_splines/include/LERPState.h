#ifndef _LERP_STATE_H
#define _LERP_STATE_H	

#include "BaseState.h"

#include <iostream>

typedef std::vector<Sprite*>::iterator it_objectList;


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
	void HandleUI(StateManager* stateMan);
};
#endif