#pragma once
#ifndef BIRD_H
#define BIRD_H

#include "SDL_utils.h"
#include "Game.h"

const int BIRD_WIDTH = 72;
const int BIRD_HEIGHT = 50;

const int WALKING_ANIMATION_FRAMES = 3;
const float GRAVITY_SPEED = 3;
const int MAX_SPEED = 10;
const float JUMP_SPEED = 25;
const float SCROLLING_SPEED = 3;
const float MAX_SCROLLING_SPEED = 5;


class LTexture : public Game
{
public:
	LTexture();
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer* renderer);

	enum Jump
	{
		JUMP_UP = 0,
	};

	//Renders texture at given point
	void render(SDL_Renderer* renderer);


	//Input keyboard
	void Inputkeyboard(SDL_Event e, SDL_Renderer* renderer);
	void loadMedia();

	bool cliiision() { return collision; };
	int Point() { return point; }

	void Movepine();
	bool checkCollision(SDL_Rect b);
	//Moves the dot and checks collision
	void move(SDL_Rect& wall);

private:

	int mWidth;
	int mHeight;


	float mVelX;
	float mVelY;

	float mPosX;
	float mPosY;


	int point;

	int frame;

	Input input;
	bool collision;
	int status;
	int mapx_;
	int mapy_;

	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

	SDL_Rect mCollider;
};

#endif // !BIRD_H
