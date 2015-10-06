#include "AGE.h"
#include "AGE_Graphics.h"

void AGE_Animation::CreateFromSpriteSheet(AGE_Sprite spritesheet, vector<AGE_Rect> cliplist, int frameTime)
{
	spriteSheet = new AGE_Sprite;
	position = new AGE_Vector;
	currentClip = new AGE_Rect;

	this->clipList = cliplist;

	this->frameTime = frameTime;
	this->spriteSheet = &spritesheet;
	this->currFrameTime = 0;
	this->currIndex = 0;
	this->IsAnimating = true;
}

void AGE_Animation::ChangeSpeed(int newSpeed)
{
	this-> frameTime = newSpeed;
}

vector<AGE_Rect> AGE_Animation::GetSpriteSheetRects(AGE_Sprite *texture,int startingId, int endId, int frameWidth, int frameHeight)
{
	int rectsPerRow = texture->GetWidth() / frameWidth;
	vector<AGE_Rect> result;

	int i;

	for (i = startingId; i <= endId; i++)
	{
		int sourceY = i / rectsPerRow;
		int sourceX = i - sourceY * rectsPerRow;
		AGE_Rect rect(sourceX * frameWidth, sourceY * frameHeight, frameWidth, frameHeight);
		result.push_back(rect);
	}

	return result;
}

void AGE_Animation::SetAlpha(Uint8 alpha)
{
	this->spriteSheet->SetAlpha(alpha);
}

AGE_Rect AGE_Animation::GetSize()
{
	AGE_Rect rect;
	rect = this->clipList.front();	
	return rect;
}

void AGE_Animation::Update(AGE_Vector newPosition, Uint32 deltaMilliSeconds)
{
	this->position->SetX(newPosition.GetX());
	this->position->SetY(newPosition.GetY());

	if(this->IsAnimating)
	{
		this->currFrameTime += deltaMilliSeconds;
			
		if(this->currFrameTime>=this->frameTime)
		{
			if(this->currIndex < this->clipList.size() - 1)
			{
				this->currIndex++;			
			}
			else
			{
				this->currIndex = 0;
			}
			
			this->currFrameTime = 0;
		}
	}
}

int AGE_Animation::GetIndex()
{
	return this->currIndex;
}

void AGE_Animation::SetIndex(int newIndex)
{
	this->currIndex= newIndex;
	this->currFrameTime = 0;
}

int AGE_Animation::ChangeState(bool state)
{
	this->IsAnimating = state;
}

void AGE_Animation::Draw(AGE_SpriteBatch *sb, double rotation, AGE_Vector *origin, SDL_RendererFlip flip, short depth)
{	
	*this->currentClip = this->clipList.at(this->currIndex);
	sb->Render(this->spriteSheet, position, this->currentClip, depth, rotation, origin, flip);
}

void AGE_Animation::Destroy()
{
	this->clipList.clear();
	this->spriteSheet->Destroy();
}