#include "AGE.h"
#include "AGE_Graphics.h"

void AGE_Sprite::Destroy()
{	
	freeTexture();
}

void AGE_Sprite::freeTexture()
{
	if( this->texture != NULL )
	{
		SDL_DestroyTexture( this->texture );
		this->texture = NULL;
		this->width = 0;
		this->height = 0;
	}
}

bool AGE_Sprite::CreateBlank(AGE_Engine *engine,int width, int height, SDL_TextureAccess access)
{
    this->texture = SDL_CreateTexture(engine->renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);

    if( this->texture == NULL )
    {
        printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
    }
    else
    {
        this->width = width;
        this->height = height;
    }

    return this->texture != NULL;
}

bool AGE_Sprite::Load(AGE_Engine* engine, char *path)
{
	freeTexture();
	
	SDL_Texture *finalTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path);

	if(loadedSurface == NULL)
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	}
	else
	{

		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        finalTexture = SDL_CreateTextureFromSurface( engine->renderer, loadedSurface );

		if( finalTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			this->width = loadedSurface->w;
			this->height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	this->texture = finalTexture;
	return finalTexture != NULL;
}

void AGE_Sprite::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod( this->texture, red, green, blue );
}

void AGE_Sprite::SetBlendMode(SDL_BlendMode blendMode)
{
	SDL_SetTextureBlendMode( this->texture, blendMode );
}
		
void AGE_Sprite::SetAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(this->texture, alpha);
}

bool AGE_Sprite::LoadFromText(AGE_Engine* engine, char* text, SDL_Color textColor, TTF_Font* font)
{
	freeTexture();

	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
	
	if(textSurface == NULL)
	{
		printf("Text redner error '%s'", TTF_GetError());
	}
	else
	{		
		this->texture = SDL_CreateTextureFromSurface(engine->renderer, textSurface);

		if(this->texture == NULL)
		{
			printf("Text render texture from surface error '%s'", text);
		}
		else
		{
			this->width = textSurface->w;
			this->height = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}

	return this->texture != NULL;
}

SDL_Texture* AGE_Sprite::GetTexture()
{
	return this->texture;
}

int AGE_Sprite::GetWidth()
{
	return this->width;
}

int AGE_Sprite::GetHeight()
{
	return this->height;
}