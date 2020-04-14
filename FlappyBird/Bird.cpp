#include "Bird.h"



LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	frame = 0;
	xval = 0;
	yval = 0;
	xpos = 0;
	ypos = 0;


}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path,SDL_Renderer* renderer)
{
	bool success = Game::LoadImage(path, renderer);
	if (success == true)
	{
		mWidth = rect_.w / 4;
		mHeight = rect_.h / 4;
	}

	return success;
}

void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(SDL_Renderer* renderer)
{

	loadFromFile("Image//bird.png", renderer);

	++frame;

	if (frame / 4 >= WALKING_ANIMATION_FRAMES)
	{
		frame = 0;
	}

	rect_.x = xpos;
	rect_.y = ypos;


	SDL_Rect* currentClip = &gSpriteClips[frame / 4];
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { rect_.x ,rect_.y , mWidth, mHeight };

	//Set clip rendering dimensions
	if (currentClip != NULL)
	{
		renderQuad.w = currentClip->w;
		renderQuad.h = currentClip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, gTexture, currentClip, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}


void LTexture:: loadMedia()
{
	
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 64;
		gSpriteClips[0].h = 205;

		gSpriteClips[1].x = 64;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 205;

		gSpriteClips[2].x = 128;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 64;
		gSpriteClips[2].h = 205;

		gSpriteClips[3].x = 196;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 205;
	
}

