#include "stdafx.h"
#include "Ball.h"

CBall::CBall(std::shared_ptr<b2World> & world, glm::vec2 position, float radius, glm::vec2 impulse, b2BodyType bodyType)
	: m_world(world)
{
	m_bodydef.position.Set(position.x, position.y);
	m_bodydef.type = bodyType;
	m_body = world->CreateBody(&m_bodydef);
	m_body->ApplyLinearImpulseToCenter(b2Vec2(impulse.x, impulse.y), true);
	m_shape.m_radius = radius;
	m_fixturedef.shape = &m_shape;
	m_fixturedef.density = 1;
	m_fixturedef.friction = 1.f;
	m_body->CreateFixture(&m_fixturedef);
}
 
/*CBall::~CBall()
{
	std::cout << "Destroying ball" << std::endl;
	m_body = nullptr;
}*/
void CBall::Draw()
{
	b2Vec2 position = m_body->GetWorldCenter();
	float angle = m_body->GetAngle();
	float step = float(2 * M_PI / AMOUNT_POINTS);
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(angle * 180 / float(M_PI), 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);

	for (float angle = 0.0; angle <= float(2 * M_PI); angle += step)
	{
		float dx = cos(angle) * GetRadius();
		float dy = sin(angle) * GetRadius();
		glVertex2f(dx, dy);
	}
	glEnd();
	glPopMatrix();
}

float CBall::GetRadius()
{
	return m_body->GetFixtureList()->GetShape()->m_radius;
}

float CBall::GetRotation()
{
	return m_body->GetAngle();
}

b2Vec2 CBall::GetPosition()
{
	return m_body->GetPosition();
}

b2Body* CBall::GetBody()
{
	return m_body;
}
