#pragma once
#ifndef BIRD_H
#define BIRD_H
#include "Function.h"
#include "Game.h"
#include "FlappyBirdMap.h"

const int WALKING_ANIMATION_FRAMES = 4;


class LTexture : public Game
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path,SDL_Renderer* renderer);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(SDL_Renderer* renderer);
	
	void loadMedia();

	//Gets image dimensions
	int getWidth();
	int getHeight();


	//Input keyboard
	void Inputkeyboard(SDL_Event e, SDL_Renderer* renderer);

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;


	float xval;
	float yval;

	float xpos;
	float ypos;


	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

	int frame;
};

#endif // !BIRD_H
