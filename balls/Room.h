#pragma once
#include "stdafx.h"
#include "DispatchEvent.h"
#include "const.h"
#include "Wall.h"
#include "Ball.h"

class CRoom
{
public:
	CRoom(glm::vec2 gravity);
	void Update(float deltaSeconds);
	void Render();
	void Fire(const SDL_Event &event);
	void RotateGun(const SDL_Event &event);
private:
	void CreateBarrier();
	void CreateGun();
	std::shared_ptr<b2World> m_room;

	std::vector<std::shared_ptr<CWall>> m_wall;
	std::vector<std::shared_ptr<CBall>> m_ball;
	std::shared_ptr<CWall> m_gun;
};

