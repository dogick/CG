#include "stdafx.h"
#include "const.h"

CRoom::CRoom(glm::vec2 gravity)
{
	m_room = std::make_unique<b2World>(b2Vec2(gravity.x, gravity.y));
	CreateBarrier();
	CreateGun();
}

void CRoom::Update(float deltaSeconds)
{
	(void)deltaSeconds;
	m_room->Step(1.f / 30.f, 8, 3);
}

void CRoom::CreateGun()
{
	m_ball.push_back(std::make_shared<CBall>(CBall(m_room, GUN_POSITION, RADIUS_CIRCLE_GUN, {0, 0}, b2BodyType::b2_staticBody)));
	m_gun = std::make_shared<CWall>(CWall(m_room, { GUN_POSITION.x - RADIUS_CIRCLE_GUN, GUN_POSITION.y - RADIUS_CIRCLE_GUN }, { 50, 20 }, float(-M_PI / 10), b2BodyType::b2_staticBody));
	m_wall.push_back(m_gun);
}

void CRoom::CreateBarrier()
{
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { WIDTH - 200, HEIGHT - 200 }, { WIDTH - 600, 10 }, float(-M_PI / 10), b2BodyType::b2_staticBody)));
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 0, HEIGHT - 180 }, { WIDTH - 300, 10 }, float(M_PI / 10), b2BodyType::b2_staticBody)));
   
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 0, HEIGHT / 2 }, { 20, HEIGHT }, 0, b2BodyType::b2_staticBody)));
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { WIDTH, HEIGHT / 2 }, { 20, HEIGHT }, 0, b2BodyType::b2_staticBody)));
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 0, 0 }, { WIDTH, 10 }, 0, b2BodyType::b2_staticBody)));

	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 650, 200 }, { 40, 20 }, 0, b2BodyType::b2_staticBody)));
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 150, 300 }, { 60, 30 }, float(M_PI / 5), b2BodyType::b2_staticBody)));
	m_wall.push_back(std::make_shared<CWall>(CWall(m_room, { 300, 450 }, { 60, 30 }, float(-M_PI / 5), b2BodyType::b2_staticBody)));
}


void CRoom::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();	
	for (auto it = m_wall.begin(); it != m_wall.end(); ++it)
	{
		(*it)->Draw();
	}
	for (auto it = m_ball.begin(); it != m_ball.end();)
	{
		if((*it)->GetPosition().y >= HEIGHT)
		{
			//m_room->DestroyBody((*it)->GetBody());
			//(*it)->~CBall();
			it = m_ball.erase(it);
	    }
		 else
		 {
			 (*it)->Draw();
			 ++it;
		 }
	}
	
	//m_ball.erase(std::remove_if(m_ball.begin(), m_ball.end(), [](CBall* ball) -> bool { return ball->GetPosition().y >= HEIGHT; }), m_ball.end());
}

void CRoom::Fire(const SDL_Event &event)
{
	glm::vec2 mousePosition = sdl::GetMousePosition(event.motion);
	glm::vec2 direction = mousePosition - GUN_POSITION;
	float angle = atan2f(direction.y, direction.x);
	m_gun->GetBody()->SetTransform(m_gun->GetPosition(), angle);
	glm::vec2 point = { float(cos(angle) * 2 * RADIUS_CIRCLE_GUN ) , float(sin(angle) * 2 * RADIUS_CIRCLE_GUN ) };
	m_ball.push_back(std::make_shared<CBall>(CBall(m_room, GUN_POSITION + point, RADIUS_CIRCLE, direction, b2_dynamicBody)));
}

void CRoom::RotateGun(const SDL_Event &event)
{
	glm::vec2 mousePosition = sdl::GetMousePosition(event.motion);
	glm::vec2 direction = mousePosition - GUN_POSITION;
	float angle = atan2f(direction.y, direction.x);
	glm::vec2 newPosition = { GUN_POSITION.x + cos(angle) * RADIUS_CIRCLE_GUN ,GUN_POSITION.y + sin(angle) * RADIUS_CIRCLE_GUN };
	m_gun->GetBody()->SetTransform({ newPosition.x, newPosition.y }, angle);
}


