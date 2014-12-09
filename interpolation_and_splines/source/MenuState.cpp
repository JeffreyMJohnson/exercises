#include "MenuState.h"

MenuState::MenuState(int width, int height)
{
	this->screenWidth = width;
	this->screenHeight = height;
	midScreenWidth = screenWidth * 0.5f;
	midScreenHeight = screenHeight * 0.5f;

};
MenuState::~MenuState(){};

void MenuState::Init()
{
}

void MenuState::Update(float timeDelta, StateManager* stateMan)
{
	HandleUI(stateMan);
}

void MenuState::Draw()
{
	DrawString("MENU", midScreenWidth - 100, screenHeight * 0.9f);
	DrawString("(1) LERP demo", midScreenWidth - 120, screenHeight *.8f);
	DrawString("(2) Quad Bezier demo", midScreenWidth - 120, screenHeight *.7f);
	DrawString("(3) Cubic Bezier demo", midScreenWidth - 120, screenHeight *.6f);
	DrawString("(4) Hermite Spline demo", midScreenWidth - 120, screenHeight *.5f);
	DrawString("<ESC> to Quit", midScreenWidth - 100, screenHeight * .1f);
}

void MenuState::Destroy()
{

}

void MenuState::HandleUI(StateManager* stateMan)
{
	if (IsKeyDown('1'))
	{
		stateMan->PushState(new LERPState(screenWidth, screenHeight));
		
	}

	if (IsKeyDown('2'))
	{
		stateMan->PushState(new QuadBezier(screenWidth, screenHeight));

	}

	if (IsKeyDown('3'))
	{
		stateMan->PushState(new CubicBezier(screenWidth, screenHeight));

	}


	if (IsKeyDown('4'))
	{
		stateMan->PushState(new HermiteSpline(screenWidth, screenHeight));

	}

	if(IsKeyDown(256))
	{
		stateMan->PopState();
	}
}