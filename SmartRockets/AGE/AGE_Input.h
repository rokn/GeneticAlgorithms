#ifndef AGE_INPUT_H
#define AGE_INPUT_H

#include "AGE.h"

//KEYBOARD INPUT

class AGE_Keyboard
{
	const Uint8 *oldKeyboardState;
	const Uint8 *currentKeyboardState;

public:
	bool KeyIsDown(SDL_Scancode);
	bool KeyIsUp(SDL_Scancode);
	void Update();
};

// bool key_is_held(KeyboardInput *, SDL_Scancode); // Not working GOTO: keyboard_input.c
// bool key_just_pressed(KeyboardInput *, SDL_Scancode); // Not working GOTO: keyboard_input.c

// MOUSE INPUT

class AGE_Mouse
{
	AGE_Vector position;

	bool leftIsPressed;
	bool rightIsPressed;
	bool middleIsPressed;
	// bool LeftJustPressed;
	// bool RightJustPressed;
	// bool MiddleJustPressed;
	void pressButton(SDL_Event *);
	void releaseButton(SDL_Event *);

public:
	void Update(SDL_Event*);
	bool LeftIsPressed();
	bool RightIsPressed();
	bool MiddleIsPressed();
	AGE_Vector GetPosition();
};

#endif