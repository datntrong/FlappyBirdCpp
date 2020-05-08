#pragma once
#ifndef BIRD_H
#define BIRD_H
#include "Function.h"
#include "Game.h"
#include "FlappyBirdMap.h"

const float GRAVITY_SPEED = 0.5;
const int MAX_SPEED = 5;
const float JUMB_SPEED = 20 ;
const float SCROLLING_SPEED = 3;
class LTexture : public Game
{
public:
	LTexture();
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer* renderer);

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
	void SetMapXY(const int mapx, const int mapy) { mapx_ = mapx; mapy_ = mapy; }
	void ScrollingMap(Map& map_data) ;
	bool cliiision() { return collision; };

private:
	
	int mWidth;
	int mHeight;


	float xval;
	float yval;

	float xpos;
	float ypos;


	

	int frame;

	Input input;
	bool collision;
	int status;
	int mapx_;
	int mapy_;
};

#endif // !BIRD_H
