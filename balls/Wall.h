#pragma once
#include "stdafx.h"
#include <iostream>

class CWall
{
public:
	CWall(std::shared_ptr<b2World> world, glm::vec2 position, glm::vec2 size, float angle, b2BodyType bodyType);
	void Draw();
	b2Body* GetBody();
	b2Vec2 GetPosition();
	float GetRotation();
private:
	b2BodyDef m_bodydef;
	b2Body* m_body;
	b2PolygonShape m_shape;
	b2FixtureDef m_fixturedef;
};

