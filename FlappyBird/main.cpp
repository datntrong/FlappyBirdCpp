

#include <iostream>
#include "SDL_utils.h"
#include "Game.h"
#include "FlappyBirdMap.h"
#include "Bird.h"


const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 500;

const char WINDOW_TITLE[] = "Flappy Bird";

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event gEvent;

Game gBackground;

bool LoadBackground()
{
	bool ret = gBackground.LoadImage("Image//background.png", gRenderer);
	if (ret == false)
		return false;
	return true;
}


int main(int argc, char* argv[])
{
	
	initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

	
	bool quit = false;

	
	if (LoadBackground() == false)
		return -5;
	gBackground.Render(gRenderer, NULL);
	

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

		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
	quitSDL(gWindow, gRenderer);
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
