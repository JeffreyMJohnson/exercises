#include "AIE.h"
#include "TheMath.h"
#include <iostream>

typedef unsigned int uInt;

struct Sprite
{
	Vector2 size;
	Vector2 position;
	uInt ID = 0;
	char* name = "";
};

struct Player
	: public Sprite
{
	bool flipDirection = false;
};

int maxWidth = 1024;
int maxHeight = 768;

const char* spriteFileName = "./images/crate_sideup.png";
Sprite* objectList[3];
float currentLERPPercent = 0.0f;

void Init()
{
	Sprite* markerStart = new Sprite;
	Sprite* markerEnd = new Sprite;
	Player* player = new Player;

	markerStart->name = "start";
	markerStart->size = Vector2(10, 10);
	markerStart->position = Vector2(10, 100);
	markerStart->ID = CreateSprite(spriteFileName, markerStart->size.x, markerStart->size.y, true);
	objectList[0] = markerStart;


	markerEnd->name = "end";
	markerEnd->size = markerStart->size;
	markerEnd->position = Vector2(900, 100);
	markerEnd->ID = markerStart->ID;
	objectList[1] = markerEnd;

	player->name = "player";
	player->size = Vector2(100, 100);
	player->position = Vector2(10, 100);
	player->ID = CreateSprite(spriteFileName, player->size.x, player->size.y, true);
	player->flipDirection = false;
	objectList[2] = player;

}

void Update(float timeDelta)
{
	Player* player = (Player*)objectList[2];

	//slow it down
	timeDelta *= .25f;

	if (currentLERPPercent >= 1)
		player->flipDirection = true;
	else if (currentLERPPercent <= 0)
		player->flipDirection = false;

	if (!player->flipDirection)
		currentLERPPercent += timeDelta;
	else
		currentLERPPercent -= timeDelta;

	//set player position
	player->position = Vector2::LERP(objectList[0]->position, objectList[1]->position, currentLERPPercent);

	
}

void Draw()
{
	for (int i = 0; i < 3; i++)
	{
		Sprite* object = objectList[i];
		MoveSprite(object->ID, object->position.x, object->position.y);
		DrawSprite(object->ID);
	}
}

void Destroy()
{
	DestroySprite(objectList[0]->ID);
	DestroySprite(objectList[2]->ID);

	for (int i = 0; i < 3; i++)
	{
		delete objectList[i];
	}
}

int main( int argc, char* argv[] )
{	
	bool quit = false;
    Initialise(maxWidth, maxHeight, false, "Test Game");
    
    SetBackgroundColour(SColour(0, 0, 0, 255));

	Init();

    //Game Loop
    do
	{
		float time = GetDeltaTime();
		
		Update(time);
		Draw();

		if (IsKeyDown(256))
			quit = true;

        ClearScreen();

    } while(!FrameworkUpdate() && !quit);
	Destroy();
    Shutdown();
	

    return 0;
}
