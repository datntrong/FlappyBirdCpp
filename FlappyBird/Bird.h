#pragma once
#ifndef BIRD_H
#define BIRD_H
#include "Function.h"
#include "Game.h"
#include "FlappyBirdMap.h"

const int GRAVITY_SPEED = 1;
const int MAX_SPEED = 10;
class LTexture : public Game
{
public:
	LTexture();
	~LTexture();
	
	//Loads image at specified path
	bool loadFromFile(std::string path,SDL_Renderer* renderer);

	enum Jumb
	{
		JUMB_UP = 0,
	};
	

	//Renders texture at given point
	void render(SDL_Renderer* renderer);
	
	


	//Input keyboard
	void Inputkeyboard(SDL_Event e, SDL_Renderer* renderer);

	void Player(Map& map_data);

	void Checkmap(Map& map_data);

private:
	
	int mWidth;
	int mHeight;


	float xval;
	float yval;

	float xpos;
	float ypos;


	

	int frame;

	Input input;
	bool onground;
	int status;
};

#endif // !BIRD_H
