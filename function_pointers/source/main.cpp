/*
Refer back to the pong exercise from weeks 1-3 or create a new program that uses a switch statement along with an enum 
to navigate through the various stages of the game (e.g Main Menu, In Game, etc.). You should replace this switch statement 
with a function pointer and have the update loop of the game process an appropriate function instead.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum STATE
{
	MENU,
	GAME,
	QUIT
};

STATE currentState = MENU;
vector<void*> funcPointers;
void(*functionPtr)() = nullptr;
map<STATE, void*> myMap;
bool quit = false;

void Menu();
void Game();
void Quit();

void LoadPtrs();

void main()
{
	
	LoadPtrs();

	while (!quit)
	{
		switch (currentState)
		{
		case MENU:

			break;
		case GAME:

			break;
		case QUIT:
			map<STATE, void*>::iterator it = myMap.find(QUIT);
			(it->second);
		}
	}
}

void Quit()
{
	quit = true;
}

void LoadPtrs()
{
	myMap[MENU] = &Menu;
	myMap[GAME] = &Game;
	myMap[QUIT] = &Quit;
}