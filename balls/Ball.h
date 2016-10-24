#pragma once
#include "stdafx.h"

class CBall
{
public:
	CBall(std::shared_ptr<b2World> & world, glm::vec2 position, float radius, glm::vec2 impulse, b2BodyType bodyType);
	//~CBall();
	void Draw();
	b2Body* GetBody();
	b2Vec2 GetPosition();
	float GetRotation();
	float GetRadius();
private:
	std::shared_ptr<b2World> m_world;
	b2BodyDef m_bodydef;
	b2Body* m_body;
	b2CircleShape m_shape;
	b2FixtureDef m_fixturedef;
};
