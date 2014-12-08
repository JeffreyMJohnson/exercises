#include "StateManager.h"

StateManager::StateManager(){};
StateManager::~StateManager(){};

void StateManager::PushState(BaseState* stateToPush)
{
	stateList.push(stateToPush);
	stateToPush->Init();
}

void StateManager::PopState()
{
	BaseState* old = stateList.top();
	old->Destroy();
	stateList.pop();
	delete old;
	if (stateList.empty())
		quitApp = true;
}

void StateManager::SwitchState(BaseState* stateToSwitch)
{
	PopState();
	PushState(stateToSwitch);
}

void StateManager::UpdateState(float timeDelta)
{
	stateList.top()->Update(timeDelta, this);
}

void StateManager::DrawState()
{
	stateList.top()->Draw();
}