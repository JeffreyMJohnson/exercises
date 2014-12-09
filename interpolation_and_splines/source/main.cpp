#include <iostream>
#include "StateManager.h"
#include "MenuState.h"


using namespace std;

int maxWidth = 1024;
int maxHeight = 768;

StateManager stateMan;

int main(int argc, char* argv[])
{
	bool quit = false;
	Initialise(maxWidth, maxHeight, false, "Test Game");

	SetBackgroundColour(SColour(0, 0, 0, 255));

	stateMan.PushState(new MenuState(maxWidth, maxHeight));

	//Game Loop
	do
	{
		ClearScreen();
		float timeDelta = GetDeltaTime();

		stateMan.UpdateState(timeDelta);
		if (stateMan.quitApp)
			break;
		stateMan.DrawState();

	} while (!FrameworkUpdate());
	Shutdown();


	return 0;
}
