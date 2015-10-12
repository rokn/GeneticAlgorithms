#include <iostream>
#include <stdlib.h>
#include "AGE/AGE.h"
#include "AGE/AGE_Graphics.h"
#include "AGE/AGE_Input.h"
#include "main.h"
#include "world.h"
//#include "BOX2D/Box2D.h"

void LoadContent(AGE_Engine *engine);
void UnloadContent();
void EventHandle(SDL_Event *event);
void Update(AGE_Engine*);
void Draw(AGE_Engine*);

AGE_SpriteBatch *sB;

AGE_Keyboard *keyboard;
AGE_Mouse *mouse;

world_t *world;

void UpdateInput();

int main()
{
	srand(time(NULL));	

	int width,height;
	AGE_Engine* engine = new AGE_Engine;
	engine->GetDesktopResolution(width,height);
	engine->Init("Helsys", width, height, true, true);

	sB = new AGE_SpriteBatch(engine);

	mouse = new AGE_Mouse;
	keyboard = new AGE_Keyboard;

	world = new world_t(50, engine);

	LoadContent(engine);

	engine->Run(EventHandle, Update, Draw);

	UnloadContent();
}

void LoadContent(AGE_Engine *engine)
{
	world->load(engine);
}

void EventHandle(SDL_Event *event)
{
	mouse->Update(event);
}

void Update(AGE_Engine* engine)
{
	keyboard->Update();

	world->update(engine);

	if(keyboard->KeyIsDown(SDL_SCANCODE_ESCAPE))
	{
		engine->Exit();
		engine->Destroy();
	}	
}

void Draw(AGE_Engine* engine)
{
	sB->DrawBegin();
	world->draw(sB);
	sB->DrawEnd(NULL);
}

void UnloadContent()
{
	world->destroy();
}