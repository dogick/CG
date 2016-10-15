#include "stdafx.h"
#include "Window.h"
#include "DispatchEvent.h"
#include "Const.h"

namespace
{

}

CWindow::CWindow()
	:m_room(new CRoom(GRAVITY))
{
}


CWindow::~CWindow()
{
}

void CWindow::OnWindowEvent(const SDL_Event &event)
{
	OnMouseDown(event);
}

void CWindow::OnUpdateWindow(float deltaSeconds)
{
	m_room->Update(deltaSeconds);
}

void CWindow::OnDrawWindow(const glm::ivec2 & size)
{
	SetupView(size);
	m_room->Render();
}

void CWindow::OnMouseDown(const SDL_Event &event)
{

}

void CWindow::SetupView(const glm::ivec2 & size)
{
	const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
	glViewport(0, 0, size.x, size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(matrix));
	glMatrixMode(GL_MODELVIEW);
}