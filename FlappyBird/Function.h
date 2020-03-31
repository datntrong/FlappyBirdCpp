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
static SDL_Renderer* gScreen = NULL;
static SDL_Event gEvent;

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;


const int RENDER_DRAW_COLOR = 0xff;




#endif // !FUNCTION_H