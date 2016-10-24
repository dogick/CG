#include "stdafx.h"
#include "Wall.h"

CWall::CWall(std::shared_ptr<b2World> world, glm::vec2 position, glm::vec2 size, float angle, b2BodyType bodyType)
{
	m_bodydef.angle = angle;
	m_bodydef.position.Set(position.x, position.y);
	m_bodydef.type = bodyType;
	m_body = world->CreateBody(&m_bodydef);
	m_shape.SetAsBox(size.x, size.y);
	m_fixturedef.shape = &m_shape;
	m_fixturedef.density = 1;
	m_fixturedef.restitution = 0.3f;
	m_body->CreateFixture(&m_fixturedef);

}


void CWall::Draw()
{
	b2Vec2 points[4];
	b2Vec2 position = m_body->GetWorldCenter();
	float angle = m_body->GetAngle();
	glColor3f(0, 0.5, 1);
	glPushMatrix();
	glTranslatef(position.x, position.y, 0);
	glRotatef(angle * 180 / float(M_PI), 0, 0, 1);

	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
	{
		points[i] = ((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->GetVertex(i);
		glVertex2f(points[i].x, points[i].y);
	}
	glEnd();
	glPopMatrix();
}


b2Vec2 CWall::GetPosition()
{
	return  m_body->GetPosition();
}

float CWall::GetRotation()
{
	return m_body->GetAngle();
}

b2Body* CWall::GetBody()
{
	return m_body;
}

