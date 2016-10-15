#pragma once
#include "stdafx.h"
#include "const.h"
#include "Wall.h"

class CRoom
{
public:
	CRoom(glm::vec2 gravity);
	void Update(float deltaSeconds);
	void Render();
private:
	void CreateWall();
	b2World* m_room;
	std::vector<CWall*> m_wall;
};

