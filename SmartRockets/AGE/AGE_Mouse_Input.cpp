#include "AGE_Input.h"
#include "AGE_Graphics.h"

void AGE_Mouse::Update(SDL_Event* event)
{
	switch(event->type)
	{
		case SDL_MOUSEMOTION:
			int x,y;
			SDL_GetMouseState(&x, &y);
			this->position.SetX((float)x);
			this->position.SetY((float)y);
			break;

		case SDL_MOUSEBUTTONDOWN:
			pressButton(event);
			break;

		case SDL_MOUSEBUTTONUP:
			releaseButton(event);
			break;
	}
}

void AGE_Mouse::pressButton(SDL_Event *event)
{
	switch(event->button.button)
	{
		case SDL_BUTTON_LEFT:
			this->leftIsPressed = true;
			break;
		case SDL_BUTTON_MIDDLE:
			this->middleIsPressed = true;
			break;
		case SDL_BUTTON_RIGHT:
			this->rightIsPressed = true;
			break;
	}
}

void AGE_Mouse::releaseButton(SDL_Event *event)
{
	switch(event->button.button)
	{
		case SDL_BUTTON_LEFT:
			this->leftIsPressed = false;
			break;
		case SDL_BUTTON_MIDDLE:
			this->middleIsPressed = false;
			break;
		case SDL_BUTTON_RIGHT:
			this->rightIsPressed = false;
			break;
	}
}

bool AGE_Mouse::LeftIsPressed()
{
	return this->leftIsPressed;
}

bool AGE_Mouse::RightIsPressed()
{
	return this->rightIsPressed;
}

bool AGE_Mouse::MiddleIsPressed()
{
	return this->middleIsPressed;
}

AGE_Vector AGE_Mouse::GetPosition()
{
	return this->position;
}