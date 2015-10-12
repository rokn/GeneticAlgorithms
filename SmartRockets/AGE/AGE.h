#ifndef AGE_H
#define AGE_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>
#include <cmath>
#include <vector>

#include "AGE_Graphics.h"


//									Classes

class AGE_Engine;
class AGE_Vector;
class AGE_Timer;
class AGE_Rect;
class AGE_Sprite;
class AGE_SpriteBatch;
class AGE_Camera;
class AGE_Animation;
class AGE_Keyboard;
class AGE_Mouse;


typedef void (*EventHandle_age)(SDL_Event *event);
typedef void (*UserUpdate_age)(AGE_Engine *engine);
typedef void (*UserDraw_age)(AGE_Engine *engine);
//									Main functions

class AGE_Engine
{
	int MAX_FPS;
	int MAX_TICKS_PER_FRAME;
	int current_fps;

	AGE_Rect* windowRect;
		
	SDL_Window *window = NULL;

	SDL_Renderer *renderer = NULL;

	Uint32 lastUpdate;

	bool quit;

	bool VSynced;

public:
	friend class AGE_Sprite;
	friend class AGE_SpriteBatch;
	AGE_Engine();
	bool Init(const char* windowTitle,int screenWidth, int screenHeight, bool fullscreen, bool vSync);
	void Run(EventHandle_age, UserUpdate_age, UserDraw_age);
	void SetMaxFPS(int);
	int GetCurrFPS();
	double DeltaSecondsGet();
	Uint32 DeltaMilliSecondsGet();
	void SetWindowSize(int,int);
	void SetRenderTarget(SDL_Texture *);
	AGE_Rect GetWindowRect();
	void FullScreenBorderless();
	void GetDesktopResolution(int& width, int& height);
	void Destroy();
	void Exit();
};


//									VECTOR

class AGE_Vector
{
	float x;
	float y;

public:
	AGE_Vector();
	AGE_Vector(const AGE_Vector& obj);
	AGE_Vector(float);
	AGE_Vector(float, float);

	AGE_Vector Add(AGE_Vector);
	AGE_Vector Subtract(AGE_Vector);
	float Distance(AGE_Vector);
	AGE_Vector Multiply(float);
	AGE_Vector Divide(float);
	float Length();
	AGE_Vector Normalize();

	float GetX();
	void SetX(float);
	float GetY();
	void SetY(float);

	void AddX(float);
	void AddY(float);

};

//									TIMER

class AGE_Timer
{
	Uint32 startTime;
	Uint32 pausedTime;

	bool IsPaused;
	bool IsStarted;

public:
	AGE_Timer();
	void Reset();
	void Start();
	void Stop();
	void Pause();
	Uint32 GetTicks();
};

//									Rectangle

class AGE_Rect
{
	int x;
	int y;
	int width;
	int height;

public:
	AGE_Rect();
	AGE_Rect(int,int);
	AGE_Rect(int,int,int,int);

	void SetPosition(int, int);
	bool Intersects(AGE_Rect);
	bool Contains(AGE_Vector);
	bool Contains(AGE_Rect);
	void Print();

	int GetX();
	void SetX(int);
	int GetY();
	void SetY(int);
	int GetWidth();
	void SetWidth(int);
	int GetHeight();
	void SetHeight(int);
};

//									Helper Methods

AGE_Vector AGE_Helper_RotatedVectorMove(AGE_Vector position, float rotation, float speed);
float AGE_Helper_FindRotation(AGE_Vector, AGE_Vector);
AGE_Vector AGE_Helper_AngleToVector(float);
AGE_Vector AGE_Helper_FindDirection(AGE_Vector, AGE_Vector);
AGE_Vector AGE_Helper_RectCenter(AGE_Rect);

#endif