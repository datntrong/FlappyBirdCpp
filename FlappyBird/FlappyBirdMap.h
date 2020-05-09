#pragma once
#pragma once
#ifndef FLAPPYBIRD_MAP_H
#define FLAPPYBIRD_H

#include"SDL_utils.h"
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
	Map getMap() const { return game_map_; };
	void SetMap(Map& map_data) { game_map_ = map_data; }
private:
	Map game_map_;
	TileMat tile_mat[MAX_TILES];
};

#endif // !GAME_MAP_H
