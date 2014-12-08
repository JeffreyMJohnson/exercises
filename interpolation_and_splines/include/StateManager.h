#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "BaseState.h"
#include <stack>

class BaseState;

class StateManager
{
public:
	StateManager();
	~StateManager();

	/*
	Add state referenced by given pointer to stack and it becomes the current running state
	NOTE:assumes the given pointer is on the heap (new called) and the responsibility to destroy
	it is this object.
	e.g. call 
	myStateManager.PushState(new SomeDerivedBaseState);
	*/
	void PushState(BaseState* stateToPush);

	/*
	Remove the current state.
	NOTE: this will destroy the current state and any reference to it will be invalid.
	*/
	void PopState();

	/*
	Switches the current state with the state referenced by given pointer.
	same as calling PopState() and then PushState(stateToSwitch).
	*/
	void SwitchState(BaseState* stateToSwitch);

	void UpdateState(float timeDelta);
	void DrawState();

	bool quitApp = false;

private:
	std::stack<BaseState*> stateList;
};
#endif