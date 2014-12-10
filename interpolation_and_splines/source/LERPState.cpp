#include "LERPState.h"

LERPState::LERPState(int width, int height)
{
	this->screenWidth = width;
	this->screenHeight = height;
}

LERPState::~LERPState(){}

void LERPState::Init()
{
	Sprite* markerStart = new Sprite;
	Sprite* markerEnd = new Sprite;
	Player* player = new Player;

	//points to adjust the bezier curve
	//p0
	curvePoints.push_back(new Vector2(50, 100));
	//p3
	curvePoints.push_back(new Vector2(1000, 100));

	markerStart->name = "start";
	markerStart->size = Vector2(10, 10);
	markerStart->position = *curvePoints[0];
	markerStart->ID = CreateSprite(spriteFileName, markerStart->size.x, markerStart->size.y, true);
	objectList.push_back(markerStart);

	markerEnd->name = "end";
	markerEnd->size = markerStart->size;
	markerEnd->position = *curvePoints[1];
	markerEnd->ID = markerStart->ID;
	objectList.push_back(markerEnd);

	player->name = "player";
	player->size = Vector2(100, 100);
	player->position = *curvePoints[0];
	player->ID = CreateSprite(spriteFileName, player->size.x, player->size.y, true);
	player->flipDirection = false;
	objectList.push_back(player);
}

void LERPState::Draw()
{
	DrawString("LERP Demo", screenWidth * 0.5f - 100, screenHeight * 0.9f);

	SColour color = SColour(0, 255, 0, 255);

	Vector2 p0 = *curvePoints[0];
	Vector2 p1 = *curvePoints[1];

	DrawLine(p0.x, p0.y, p1.x, p1.y, color);

	//draw sprites
	for (int i = 0; i < objectList.size(); i++)
	{
		Sprite* object = objectList[i];
		MoveSprite(object->ID, object->position.x, object->position.y);
		DrawSprite(object->ID);
	}

	DrawString("<M> to return to MENU", screenWidth * 0.5f - 200, 50);

}

void LERPState::Update(float timeDelta, StateManager* stateMan)
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

	HandleUI(stateMan);
}

void LERPState::Destroy()
{
	DestroySprite(objectList[0]->ID);
	DestroySprite(objectList[2]->ID);

	for (int i = 0; i < objectList.size(); i++)
	{
		delete objectList[i];
	}

	for (int i = 0; i < curvePoints.size(); i++)
	{
		delete curvePoints[i];
	}
}

void LERPState::HandleUI(StateManager* stateMan)
{
	if (IsKeyDown('M'))
	{
		stateMan->PopState();
		return;
	}


	if (GetMouseButtonDown(MOUSE_BUTTON_1) && !clicked)
	{
		clicked = true;
		std::cout << "clicked\n";
		//loop through objects and see if clicked
		for (Sprite* object : objectList)
		{
			if (object->ID == objectList[0]->ID)
			{
				double mousePosX = 0.0;
				double mousePosY = 0.0;
				GetMouseLocation(mousePosX, mousePosY);
				bool isCollided = object->IsCollided(Vector2(mousePosX, mousePosY));
				std::cout << "object: " << object->name << " clicked: " << isCollided << std::endl;
			}
		}
	}
	if (GetMouseButtonReleased(MOUSE_BUTTON_1) && clicked)
	{
		std::cout << "released\n";
		clicked = false;
	}
}