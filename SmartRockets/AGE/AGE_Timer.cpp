#include "AGE.h"
#include "AGE_Graphics.h"

AGE_Timer::AGE_Timer()
{
	Reset();
}

void AGE_Timer::Reset()
{
	this->IsStarted = false;
	this->IsPaused = false;
	this->pausedTime = 0;
	this->startTime = 0;
}

void AGE_Timer::Start()
{
	if(this->IsStarted && this->IsPaused)
	{
		this->startTime = SDL_GetTicks() - this->pausedTime;
		this->IsPaused = false;
		this->pausedTime = 0;
	}
	else
	{
		this->IsStarted = true;
		this->startTime = SDL_GetTicks();
		this->IsPaused = false;
		this->pausedTime = 0;
	}
}

void AGE_Timer::Stop()
{
	this->IsStarted = false;
	this->startTime = 0;
	this->IsPaused = 0;
	this->pausedTime = 0;
}

void AGE_Timer::Pause()
{
	if(this->IsStarted && !this->IsPaused)
	{
		this->IsPaused = true;
		this->pausedTime = SDL_GetTicks() - this->startTime;
	}
}

Uint32 AGE_Timer::GetTicks()
{
	Uint32 timerTime = 0;

	if(this->IsStarted)
	{
		if(this->IsPaused)
		{
			timerTime = this->pausedTime;
		}
		else
		{
			timerTime = SDL_GetTicks() - this->startTime;
		}
	}

	return timerTime;
};