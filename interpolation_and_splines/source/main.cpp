#include <iostream>
#include "StateManager.h"
#include "MenuState.h"


using namespace std;

int maxWidth = 1024;
int maxHeight = 768;

StateManager stateMan;

void Update(float timeDelta)
{
	//set player position
	/*player->position = Vector2::CubicBezier(objectList[0]->position, objectList[1]->position, objectList[2]->position, objectList[3]->position, currentLERPPercent);*/
	//player->position = Vector2::HermiteSpline(objectList[0]->position, objectList[3]->position, objectList[1]->position, objectList[2]->position, currentLERPPercent);

}

void Draw()
{
	
	//draw curve
	//for (int i = 0; i < 100; i++)
	//{
	//	float t = i / 100.0f;
	//	float nextT = (i + 1) / 100.0f;

	//	Vector2 start = Vector2::CubicBezier(p0, p1, p2, p3, t);
	//	Vector2 end = Vector2::CubicBezier(p0, p1, p2, p3, nextT);

	//	DrawLine(start.x, start.y, end.x, end.y, color);
	//}
	//for (int i = 0; i < 100; i++)
	//{
	//	float t = i / 100.0f;
	//	float nextT = (i + 1) / 100.0f;

	//	Vector2 start = Vector2::HermiteSpline(p0, p3, p1, p2, t);
	//	Vector2 end = Vector2::HermiteSpline(p0, p3, p1, p2, nextT);

	//	DrawLine(start.x, start.y, end.x, end.y, color);
	//}


}

void Destroy()
{

}



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
	Destroy();
	Shutdown();


	return 0;
}
