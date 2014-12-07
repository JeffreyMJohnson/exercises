#include "AIE.h"
#include "TheMath.h"
#include <iostream>
#include <vector>

typedef unsigned int uInt;

using namespace std;

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
vector<Sprite*> objectList;
float currentLERPPercent = 0.0f;

void Init()
{
	Sprite* markerStart = new Sprite;
	Sprite* markerEnd = new Sprite;
	Player* player = new Player;
	Sprite* p01 = new Sprite;
	Sprite* p02 = new Sprite;

	markerStart->name = "start";
	markerStart->size = Vector2(10, 10);
	markerStart->position = Vector2(10, 100);
	markerStart->ID = CreateSprite(spriteFileName, markerStart->size.x, markerStart->size.y, true);
	objectList.push_back(markerStart);

	p01->name = "p01";
	p01->size = markerStart->size;
	p01->position = Vector2(200, 450);
	p01->ID = markerStart->ID;
	objectList.push_back(p01);

	p02->name = "p02";
	p02->size = markerStart->size;
	p02->position = Vector2(750, 400);
	p02->ID = markerStart->ID;
	objectList.push_back(p02);

	markerEnd->name = "end";
	markerEnd->size = markerStart->size;
	markerEnd->position = Vector2(900, 100);
	markerEnd->ID = markerStart->ID;
	objectList.push_back(markerEnd);

	player->name = "player";
	player->size = Vector2(100, 100);
	player->position = Vector2(10, 100);
	player->ID = CreateSprite(spriteFileName, player->size.x, player->size.y, true);
	player->flipDirection = false;
	objectList.push_back(player);

}

void Update(float timeDelta)
{


	Player* player = (Player*)objectList[4];

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
	//player->position = Vector2::LERP(objectList[0]->position, objectList[1]->position, currentLERPPercent);
	player->position = Vector2::CubicBezier(objectList[0]->position, objectList[1]->position, objectList[2]->position, objectList[3]->position, currentLERPPercent);

	
}

void Draw()
{
	SColour color = SColour(0, 255, 0, 255);

	Vector2 p0(10, 10);
	Vector2 p1(200, 450);
	Vector2 p2(750, 400);
	Vector2 p3(900, 100);

	for (int i = 0; i < 100; i++)
	{
		float t = i / 100.0f;
		float nextT = (i + 1) / 100.0f;

		Vector2 start = Vector2::CubicBezier(p0, p1, p2, p3, t);
		Vector2 end = Vector2::CubicBezier(p0, p1, p2, p3, nextT);

		DrawLine(start.x, start.y, end.x, end.y, color);
	}

	for (int i = 0; i < objectList.size(); i++)
	{
		Sprite* object = objectList[i];
		MoveSprite(object->ID, object->position.x, object->position.y);
		DrawSprite(object->ID);
	}
}

void Destroy()
{
	DestroySprite(objectList[0]->ID);
	DestroySprite(objectList[4]->ID);

	for (int i = 0; i < objectList.size(); i++)
	{
		delete objectList[i];
	}
}

int main( int argc, char* argv[] )
{	
	bool quit = false;
    Initialise(maxWidth, maxHeight, false, "Test Game");
    
    //SetBackgroundColour(SColour(0, 0, 0, 255));

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
