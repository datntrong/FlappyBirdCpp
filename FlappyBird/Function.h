#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static SDL_Event gEvent;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 0;
const int COLOR_KEY_G = 0xFF;
const int COLOR_KEY_B = 0xFF;


const int RENDER_DRAW_COLOR = 0xFF;

const int TILE_SIZE = 50;

const int MAX_MAP_X = 400;
const int MAX_MAP_Y = 10;
typedef struct Map
{
	int start_x_;
	int start_y_;

	int max_x_;
	int max_y_;

	int tile[MAX_MAP_Y][MAX_MAP_X];
	//char gif ddo
};

typedef struct Input
{

	int down_;
	int up_;
};




#endif // !FUNCTION_H