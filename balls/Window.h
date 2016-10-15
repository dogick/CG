#pragma once
#include "stdafx.h"
#include "AbstractWindow.h"
#include "Room.h"


class CWindow : public CAbstractWindow
{
public:
	CWindow();
	~CWindow();
protected:
	void OnWindowEvent(const SDL_Event &event) override;

	void OnUpdateWindow(float deltaSeconds) override;

	void OnDrawWindow(const glm::ivec2 & size) override;
	void OnMouseDown(const SDL_Event &event);

private:
	void SetupView(const glm::ivec2 & size);
	std::shared_ptr<CRoom> m_room;
	glm::vec2 m_dragOffset;
};