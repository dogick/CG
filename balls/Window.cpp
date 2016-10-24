#include "stdafx.h"
#include "Window.h"
#include "DispatchEvent.h"
#include "Const.h"

namespace
{
	/*void LoadTexture()
	{
		SDL_Surface* image = SDL_LoadBMP("ball.bmp");
		if (image == NULL) {
			printf("SDL_Error: %s\n", SDL_GetError());
			return;
		}

		glEnable(GL_TEXTURE_2D);

		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexImage2D(GL_TEXTURE_2D, 0, image->format->BytesPerPixel, image->w, image->h, 0, 0, GL_UNSIGNED_BYTE, image->pixels);




		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(100, 100, 0.0f);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(128.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(128.0f, 128.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(0.0f, 128.0f, 0.0f);
		glEnd();
		glPopMatrix();

	}*/
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
	//LoadTexture();
	m_room->Render();
}

void CWindow::OnMouseDown(const SDL_Event &event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		m_room->Fire(event);
	}
	else
	{
		m_room->RotateGun(event);
	}

}

void CWindow::SetupView(const glm::ivec2 & size)
{
	const glm::mat4 matrix = glm::ortho<float>(0, float(size.x), float(size.y), 0);
	glViewport(0, 0, size.x, size.y);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(matrix));
	glMatrixMode(GL_MODELVIEW);
}