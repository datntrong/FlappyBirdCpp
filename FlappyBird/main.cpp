

#include <iostream>
#include "Function.h"
#include "Game.h"
#include "FlappyBirdMap.h"

#include "Bird.h"


Game gBackground;


bool init()
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
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL)
			success = false;
		else
		{
			SDL_SetRenderDrawColor(gRenderer, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
				success = false;
		}
	}

	
	return success;
}



bool LoadBackground()
{
	bool ret = gBackground.LoadImage("Image//background.png", gRenderer);
	if (ret == false)
		return false;
	return true;
}

void close()
{
	gBackground.Free();
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	IMG_Quit;
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	
	if (init() == false)
		return -1;

	
	bool quit = false;

	
	if (LoadBackground() == false)
		return -5;
	gBackground.Render(gRenderer, NULL);
	//printmenu(gRenderer);

	FlappyBirdMap game_map;
	game_map.LoadMap();
	game_map.LoadTiles(gRenderer);

	LTexture bird;
	bird.loadFromFile("Image//bird3.png", gRenderer);
	bird.loadMedia();
	

	
	while (!quit)
	{
		

		while (SDL_PollEvent(&gEvent) != 0)
		{
			if (gEvent.type == SDL_QUIT)
			{
				quit = true;

			}

			bird.Inputkeyboard(gEvent, gRenderer);
		}
		if (bird.cliiision() == true) quit = true;

		SDL_SetRenderDrawColor(gRenderer, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(gRenderer);
		gBackground.Render(gRenderer, NULL);
		
		game_map.DrawMap(gRenderer);
		
		Map map_data = game_map.getMap();
		bird.SetMapXY(map_data.start_x_, map_data.start_y_);
		bird.Player(map_data);
		
		bird.render(gRenderer);

		SDL_RenderPresent(gRenderer);
		game_map.SetMap(map_data);
		game_map.DrawMap(gRenderer);
		
		
		SDL_Delay(50);
	}
	close();
	return 0;
}

int printmenu(SDL_Renderer* des) {
	int statButtonX = 40;
	int startButtonY = 300;
	
	int quitButtonX = 210;
	int quitButtonY = 300;
	
	Game Button1, Button2;
	Button1.LoadImage("Image//startButton.png", des);
	Button1.SetRect(statButtonX, startButtonY);
	Button1.Render(des, NULL);
	Button2.LoadImage("Image//quitButton.png", des);
	Button2.SetRect(quitButtonX, quitButtonY);
	Button2.Render(des, NULL);
	return 0;
}