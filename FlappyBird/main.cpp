

#include <iostream>
#include "Function.h"
#include "Game.h"


Game gBackground;

bool Init()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) return false;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	gWindow = SDL_CreateWindow("Flappy Bird",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		success = false;
	}
	else
	{
		gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gScreen == NULL)
			success = false;
		else
		{
			SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
				success = false;
		}
	}
	return success;
}


bool LoadBackground()
{
	bool ret = gBackground.LoadImage("Image//background.png", gScreen);
	if (ret == false)
		return false;
	return true;
}

void close()
{
	gBackground.Free();
	SDL_DestroyRenderer(gScreen);
	gScreen = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	IMG_Quit;
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	if (Init() == false)
		return -1;
	if (LoadBackground() == false)
		return -5;




	bool is_quit = false;
	while (!is_quit)
	{
		while (SDL_PollEvent(&gEvent) != 0)
		{
			if (gEvent.type == SDL_QUIT)
			{
				is_quit = true;
			}

		}

		SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(gScreen);
		gBackground.Render(gScreen, NULL);
		


		SDL_RenderPresent(gScreen);


	}
	close();
	return 0;
}
