#include "stdafx.h"


CRoom::CRoom(glm::vec2 gravity)
{
	m_room = new b2World(b2Vec2(gravity.x, gravity.y));
	CreateWall();
}

void CRoom::Update(float deltaSeconds)
{
	(void)deltaSeconds;
	m_room->Step(1.f / 60.f, 8, 3);
}


void CRoom::CreateWall()
{
	m_wall.push_back(new CWall(m_room, { WIDTH - 200, HEIGHT - 200 }, { WIDTH - 600, 10 }, float(-M_PI / 10), b2BodyType::b2_staticBody));
	m_wall.push_back(new CWall(m_room, { 0, HEIGHT - 180 }, { WIDTH - 300, 10 }, float(M_PI / 10), b2BodyType::b2_staticBody));
   
	m_wall.push_back(new CWall(m_room, { 0, HEIGHT / 2 }, { 20, HEIGHT }, 0, b2BodyType::b2_staticBody));
	m_wall.push_back(new CWall(m_room, { WIDTH, HEIGHT / 2 }, { 20, HEIGHT }, 0, b2BodyType::b2_staticBody));
	m_wall.push_back(new CWall(m_room, { 0, 0 }, { WIDTH, 10 }, 0, b2BodyType::b2_staticBody));

	m_wall.push_back(new CWall(m_room, { 650, 200 }, { 40, 20 }, 0, b2BodyType::b2_staticBody));
	m_wall.push_back(new CWall(m_room, { 150, 300 }, { 60, 30 }, float(M_PI / 5), b2BodyType::b2_staticBody));
	m_wall.push_back(new CWall(m_room, { 300, 450 }, { 60, 30 }, float(-M_PI / 5), b2BodyType::b2_staticBody));
}

void CRoom::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	for (auto it = m_wall.begin(); it  != m_wall.end(); ++it)
	{
		(*it)->Draw();
	}
}


/*if ((*it)->GetBody()->GetAngle() > float(-M_PI / 13))
{
	std::cout << "fg" << std::endl;
	m_room->DestroyBody((*it)->GetBody());
	it = m_wall.erase(it);
	std::cout << m_wall.size() << std::endl;
}*/ 