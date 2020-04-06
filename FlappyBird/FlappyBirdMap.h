#pragma once
#pragma once
#ifndef FLAPPYBIRD_MAP_H
#define FLAPPYBIRD_H

#include"Function.h"
#include "Game.h"

const int MAX_TILES = 10;

class TileMat : public Game
{
public:
	TileMat() { ; }
	~TileMat() { ; }

};

class FlappyBirdMap
{
public:
	FlappyBirdMap() { ; }
	~FlappyBirdMap() { ; }

	void LoadMap();
	void LoadTiles(SDL_Renderer* screen);
	void DrawMap(SDL_Renderer* screen);
private:
	Map game_map_;
	TileMat tile_mat[MAX_TILES];
};

#endif // !GAME_MAP_H
