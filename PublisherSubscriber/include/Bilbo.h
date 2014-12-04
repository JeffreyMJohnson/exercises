#pragma once

#include "Observer.h"
#include "Vector2.h"

class Bilbo : public Observer
{
public:
	Bilbo(void);
	~Bilbo(void);

	void initWithFile(const char* szFilename);
	void destroy();

	void OnMessage(Message& msg);
	void draw();

protected:
	int m_sprite;
	const int m_width = 58;
	const int m_height = 118;
	bool m_isAlive;
	Vector2 m_position;
};

