#include "AIE.h"
#include "Bilbo.h"
#include "GameDefs.h"

Bilbo::Bilbo(void)
{
	m_sprite = -1;
	m_isAlive = false;
	m_position.x = iScreenWidth >> 1;
	m_position.y = iScreenHeight >> 1;
}


Bilbo::~Bilbo(void)
{
}

void Bilbo::initWithFile(const char* szFilename)
{
	m_sprite = CreateSprite(szFilename, m_width, m_height, true);
}

void Bilbo::destroy()
{
	DestroySprite(m_sprite);
}

void Bilbo::OnMessage(Message& msg)
{
	//if cat dead && msg = spawn -> respawn
	if (msg.msg == Message::SPAWN_REQUEST && !m_isAlive)
	{
		Vector2* pos = static_cast<Vector2*>(msg.data);
		m_position.x = pos->x;
		m_position.y = pos->y;
		MoveSprite(m_sprite, m_position.x, m_position.y);
		m_isAlive = true;
		msg.consumed = true;
		return;
	}

	if (msg.msg == Message::ON_CLICK && m_isAlive)
	{
		Vector2* pos = static_cast<Vector2*>(msg.data);
		const float left = m_position.x - (m_width * 0.5f);
		const float right = m_position.x + (m_width * 0.5f);
		const float bottom = m_position.y - (m_height * 0.5f);
		const float top = m_position.y + (m_height * 0.5f);
		if (pos->x >= left && pos->x <= right && pos->y <= top && pos->y >= bottom)
		{
			m_isAlive = false;
			msg.consumed = true;
		}
	}

}



void Bilbo::draw()
{
	if (m_isAlive == false || m_sprite < 0)
		return;

	DrawSprite(m_sprite);
}