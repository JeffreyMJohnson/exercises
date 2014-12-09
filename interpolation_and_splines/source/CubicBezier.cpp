#include "CubicBezier.h"

CubicBezier::CubicBezier(int width, int height)
{
	screenWidth = width;
	screenHeight = height;
}

CubicBezier::~CubicBezier()
{
}

void CubicBezier::Init()
{
	Sprite* markerStart = new Sprite;
	Sprite* markerEnd = new Sprite;
	Player* player = new Player;
	Sprite* p01 = new Sprite;
	Sprite* p02 = new Sprite;

	//points to adjust the bezier curve
	//p0
	curvePoints.push_back(new Vector2(50, 100));
	//p1
	curvePoints.push_back(new Vector2(200, 500));
	//p2
	curvePoints.push_back(new Vector2(500, 700));
	//p3
	curvePoints.push_back(new Vector2(1000, 100));

	markerStart->name = "start";
	markerStart->size = Vector2(10, 10);
	markerStart->position = *curvePoints[0];
	markerStart->ID = CreateSprite(spriteFileName, markerStart->size.x, markerStart->size.y, true);
	objectList.push_back(markerStart);

	p01->name = "p01";
	p01->size = markerStart->size;
	p01->position = *curvePoints[1];
	p01->ID = markerStart->ID;
	objectList.push_back(p01);

	p02->name = "p02";
	p02->size = markerStart->size;
	p02->position = *curvePoints[2];
	p02->ID = markerStart->ID;
	objectList.push_back(p02);

	markerEnd->name = "end";
	markerEnd->size = markerStart->size;
	markerEnd->position = *curvePoints[3];
	markerEnd->ID = markerStart->ID;
	objectList.push_back(markerEnd);

	player->name = "player";
	player->size = Vector2(100, 100);
	player->position = *curvePoints[0];
	player->ID = CreateSprite(spriteFileName, player->size.x, player->size.y, true);
	player->flipDirection = false;
	objectList.push_back(player);
}

void CubicBezier::Draw()
{
	DrawString("Cubic Bezier Demo", screenWidth * 0.5f - 200, screenHeight * 0.9f);

	SColour color = SColour(0, 255, 0, 255);

	Vector2 p0 = *curvePoints[0];
	Vector2 p1 = *curvePoints[1];
	Vector2 p2 = *curvePoints[2];
	Vector2 p3 = *curvePoints[3];

	//draw curve
	for (int i = 0; i < 100; i++)
	{
		float t = i / 100.0f;
		float nextT = (i + 1) / 100.0f;

		Vector2 start = Vector2::CubicBezier(p0, p1, p2, p3, t);
		Vector2 end = Vector2::CubicBezier(p0, p1, p2, p3, nextT);

		DrawLine(start.x, start.y, end.x, end.y, color);
	}

	//draw sprites
	for (int i = 0; i < objectList.size(); i++)
	{
		Sprite* object = objectList[i];
		MoveSprite(object->ID, object->position.x, object->position.y);
		DrawSprite(object->ID);
	}

	DrawString("<M> to return to MENU", screenWidth * 0.5f - 200, 50);
}

void CubicBezier::Update(float timeDelta, StateManager* stateMan)
{
	Player* player = (Player*)GetSprite("player");
	assert(player != nullptr);

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

	player->position = Vector2::CubicBezier(GetSprite("start")->position, GetSprite("p01")->position, GetSprite("p02")->position, GetSprite("end")->position, currentLERPPercent);

	HandleUI(stateMan);
}

void CubicBezier::Destroy()
{
	DestroySprite(GetSprite("start")->ID);//little ones
	DestroySprite(GetSprite("player")->ID);//player

	for (int i = 0; i < objectList.size(); i++)
	{
		delete objectList[i];
	}

	for (int i = 0; i < curvePoints.size(); i++)
	{
		delete curvePoints[i];
	}
}

Sprite* CubicBezier::GetSprite(const char* objectName)
{
	Sprite* r = nullptr;
	for (Sprite* object : objectList)
	{
		if (object->name == objectName)
			return r = object;
	}
	return r;
}

void CubicBezier::HandleUI(StateManager* stateMan)
{
	if (IsKeyDown('M'))
		stateMan->PopState();
}