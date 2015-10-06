#include "AGE_Input.h"

//TODO: Think of a way to implement | reminder: problem is pointers of oldState


// bool key_is_held(KeyboardInput * input, SDL_Scancode scancode)
// {
// 	return input->oldKeyboardState[scancode] && input->oldKeyboardState[scancode] == input->currentKeyboardState[scancode];
// }


// bool key_just_pressed(KeyboardInput *input, SDL_Scancode scancode)
// {
// 	if(input->currentKeyboardState[SDL_SCANCODE_0])
// 	{
// 		printf("%d",input->oldKeyboardState[scancode]);
// 	}

// 	return input->currentKeyboardState[scancode] && input->oldKeyboardState[scancode] != input->currentKeyboardState[scancode];
// }



bool AGE_Keyboard::KeyIsDown(SDL_Scancode scancode)
{
	return this->currentKeyboardState[scancode];
}

bool AGE_Keyboard::KeyIsUp(SDL_Scancode scancode)
{
	return this->currentKeyboardState[scancode];
}

void AGE_Keyboard::Update()
{
	// input->oldKeyboardState = input->currentKeyboardState;
	this->currentKeyboardState = SDL_GetKeyboardState(NULL);
}