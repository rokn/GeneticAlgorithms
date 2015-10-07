#include "AGE.h"
#include "AGE_Graphics.h"

// bool testIterator(void *rSprite);
void renderSpriteIterator(SDL_Renderer*, renderSprite_age, AGE_Camera*);

AGE_Rect AGE_ViewRect;

AGE_SpriteBatch::AGE_SpriteBatch(AGE_Engine *engine)
{
	this->renderer = engine->renderer;
}

void AGE_SpriteBatch::DrawBegin()
{
	this->renderSprites.clear();
}

void AGE_SpriteBatch::Render(AGE_Sprite* sprite, AGE_Vector *pos, AGE_Rect* clip, short depth, double rotation, AGE_Vector *origin, SDL_RendererFlip flip)
{
	SDL_Rect renderRect = {(int)(pos->GetX()), (int)(pos->GetY()), sprite->GetWidth(), sprite->GetHeight()};

	renderSprite_age renderSprite;

	if(clip!=NULL)
	{
		renderRect.w = clip->GetWidth();
		renderRect.h = clip->GetHeight();
		renderSprite.clip = (SDL_Rect){clip->GetX(), clip->GetY(), clip->GetWidth(), clip->GetHeight()};
	}

	AGE_Rect imageRect = (AGE_Rect){renderRect.x, renderRect.y, renderRect.w, renderRect.h};	

	if(!imageRect.Intersects(AGE_ViewRect))
	{

		return;
	}

	renderSprite.sprite = sprite;
	renderSprite.pos = pos;	
	renderSprite.renderRect = renderRect;
	renderSprite.rotation = rotation;
	renderSprite.flip = flip;
	renderSprite.depth = depth;

	SDL_Point sdlOrigin;

	if(origin!=NULL)
	{
		sdlOrigin.x = (int)origin->GetX();
		sdlOrigin.y = (int)origin->GetY();
	}
	else
	{
		sdlOrigin.x = 0;
		sdlOrigin.y = 0;
	}

	renderSprite.origin = sdlOrigin;

	
	bool inserted = false;
	for (vector<renderSprite_age>::iterator it = this->renderSprites.begin(); it != this->renderSprites.end(); ++it)
	{		
		if((*it).depth>renderSprite.depth)
		{
			this->renderSprites.insert(it, renderSprite);
			inserted = true;			
			break;
		}
	}

	if(!inserted)
	{
		this->renderSprites.push_back(renderSprite);		
	}
}




void AGE_SpriteBatch::DrawEnd(AGE_Camera* camera)
{
	vector<renderSprite_age>::iterator it;

	for (it = this->renderSprites.begin(); it != this->renderSprites.end(); ++it)
	{				
		renderSpriteIterator(this->renderer, *it, camera);
	}

	
}

void renderSpriteIterator(SDL_Renderer* renderer, renderSprite_age rSprite, AGE_Camera* camera)
{
	if(camera != NULL)
	{
		rSprite.renderRect.x -= (int)camera->GetOffset().GetX();
		rSprite.renderRect.y -= (int)camera->GetOffset().GetY();
	}	

	SDL_RenderCopyEx(renderer, rSprite.sprite->GetTexture(), NULL, &(rSprite.renderRect), rSprite.rotation, &rSprite.origin, rSprite.flip);	
}