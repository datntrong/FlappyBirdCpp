#pragma once
#ifndef SDL_UTILS
#define SDL_UTILS
#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <sstream>
const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

const int SCREEN_BPP = 32;
const int SPACE = 150;
const int COLOR_KEY_R = 0;
const int COLOR_KEY_G = 0xFF;
const int COLOR_KEY_B = 0xFF;
const int PINE_H = 287;






void logSDLError(std::ostream& os,
	const std::string& msg, bool fatal = false);

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer,
	int screenWidth, int screenHeight, const char* windowTitle, TTF_Font*& font);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);


#endif // !SDL_UTILS
