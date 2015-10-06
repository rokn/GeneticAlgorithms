#ifndef AGE_GRAPHICS_H
#define AGE_GRAPHICS_H

#include <vector>
#include "AGE.h"

using namespace std;

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


extern AGE_Rect AGE_ViewRect;

//									SPRITE

class AGE_Sprite
{	
	SDL_Texture* texture;
	int width;
	int height;
	void freeTexture();

public:
	void Destroy();
	bool Load(AGE_Engine*, char*);
	bool CreateBlank(AGE_Engine*, int, int, SDL_TextureAccess);
	bool LoadFromText(AGE_Engine*, char*, SDL_Color, TTF_Font*);	
	void SetColor(Uint8, Uint8, Uint8);
	void SetBlendMode(SDL_BlendMode);
	void SetAlpha(Uint8);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
};

//									RENDERSPRITE

typedef struct{
	AGE_Sprite *sprite;
	AGE_Vector *pos;
	SDL_Rect clip;
	SDL_Rect renderRect;
	double rotation;
	SDL_Point origin;
	SDL_RendererFlip flip;
	short depth;
}renderSprite_age;

//									SPRITEBATCH

class AGE_SpriteBatch
{
	SDL_Renderer *renderer;
	vector<renderSprite_age> renderSprites;

public:
	AGE_SpriteBatch(AGE_Engine*);
	void DrawBegin();
	void Render(AGE_Sprite*, AGE_Vector*, AGE_Rect*, short, double, AGE_Vector *, SDL_RendererFlip);
	void DrawEnd(AGE_Camera*);
};

//									CAMERA 

class AGE_Camera
{
	AGE_Vector *Offset;
	AGE_Vector *velocity;
	bool IsFocusing;
	AGE_Rect *focusRect;
	float focusMultiplier;

public:
	AGE_Camera(AGE_Vector);
	void Update();
	void SetTransform(AGE_Vector);
	void ChangeTransform(AGE_Vector);
	AGE_Vector GetOffset();
	AGE_Vector GetOffsetMousePosition(AGE_Mouse *);
	void FocusOn(AGE_Rect, float);	
};

//									ANIMATION

class AGE_Animation
{
	vector<AGE_Rect> clipList;
	AGE_Sprite *spriteSheet;
	AGE_Vector *position;
	int frameTime;
	int currFrameTime;
	int currIndex;
	AGE_Rect *currentClip;
	bool IsAnimating;

public:
	void CreateFromSpriteSheet(AGE_Sprite, vector<AGE_Rect>, int);
	static vector<AGE_Rect> GetSpriteSheetRects(AGE_Sprite *,int, int, int, int);
	void SetAlpha(Uint8);
	AGE_Rect GetSize();
	int GetIndex();
	void ChangeSpeed(int);
	void SetIndex(int);
	int ChangeState(bool);
	void Update(AGE_Vector, Uint32);
	void Draw(AGE_SpriteBatch*, double, AGE_Vector*, SDL_RendererFlip, short);
	void Destroy();
};

#endif