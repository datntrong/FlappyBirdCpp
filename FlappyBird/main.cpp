

#include <iostream>
#include "SDL_utils.h"
#include "Game.h"
#include "Bird.h"
#include <ctime>
#include <cstdlib>
using namespace std;



const char WINDOW_TITLE[] = "Flappy Bird";

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event gEvent;
TTF_Font* gFont = NULL;
int maxpoint = 0;
Game gBackground;
Audio birddie;
Audio sound;
bool LoadBackground()
{
	bool ret = gBackground.LoadImage("Image//background.png", gRenderer);
	if (ret == false)
		return false;
	return true;
}


int main(int argc, char* argv[])
{

	initSDL(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, gFont);

	if (LoadBackground() == false)
		return -5;
	srand(time(0));
	bool quit1 = false;
	bool quit2 = false;
	bool quit = false;
	bool playntime = false;

	while (!quit1)
	{
		while (!quit2)
		{

			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);


			gBackground.Render(gRenderer, NULL);

			int statButtonX = 153;
			int startButtonY = 300;

			int quitButtonX = 603;
			int quitButtonY = 300;

			int logoX = 400;
			int logoY = 30;

			Game Button1, Button2, logo;
			Button1.LoadImage("Image//startButton.png", gRenderer);
			Button1.SetRect(statButtonX, startButtonY);
			Button1.Render(gRenderer, NULL);
			Button2.LoadImage("Image//quitButton.png", gRenderer);
			Button2.SetRect(quitButtonX, quitButtonY);
			Button2.Render(gRenderer, NULL);
			logo.LoadImage("Image//logo.png", gRenderer);
			logo.SetRect(logoX, logoY);
			logo.Render(gRenderer, NULL);
			SDL_RenderPresent(gRenderer);

			while (SDL_PollEvent(&gEvent) != 0)
			{
				if (gEvent.type == SDL_QUIT)
				{
					quit2 = true;

				}
				if (gEvent.type == SDL_MOUSEBUTTONDOWN && gEvent.button.button == SDL_BUTTON_LEFT)
				{
					int mouseX = gEvent.button.x;
					int mouseY = gEvent.button.y;
					if ((mouseX > statButtonX) && (mouseX < statButtonX + 145) &&
						(mouseY > startButtonY) && (mouseY < startButtonY + 63))
					{

						quit1 = false;
						quit2 = true;

					};
					if ((mouseX > quitButtonX) && (mouseX < quitButtonX + 145) &&
						(mouseY > quitButtonY) && (mouseY < quitButtonY + 62))
					{

						quit2 = true;
						quit1 = true;

					}
				}

			}



		}

		// play one time

		if (!quit1)
		{
			sound.load("Audio//sound.wav");
			sound.play();


			LTexture bird;
			bird.loadFromFile("Image//bird3.png", gRenderer);
			bird.loadMedia();

			Game ground;
			ground.LoadImage("Image//ground.png", gRenderer);
			ground.SetRect(0, 440);
			SDL_Rect gr = ground.GetRect();

			int ypine1 = rand() % 130 + 60, ypine2 = rand() % 130 + 60, ypine3 = rand() % 130 + 60, ypine4 = rand() % 130 + 60, ypine5 = rand() % 130 + 60;
			int xpine1 = 900, xpine2 = 1100, xpine3 = 1300, xpine4 = 1500, xpine5 = 1700;
			Game pine1, pine2, pine3, pine4, pine5, pine1top, pine2top, pine3top, pine4top, pine5top;
			pine1.LoadImage("Image//3.png", gRenderer);
			pine2.LoadImage("Image//3.png", gRenderer);
			pine3.LoadImage("Image//3.png", gRenderer);
			pine4.LoadImage("Image//3.png", gRenderer);
			pine5.LoadImage("Image//3.png", gRenderer);
			pine1top.LoadImage("Image//pinetop.png", gRenderer);
			pine2top.LoadImage("Image//pinetop.png", gRenderer);
			pine3top.LoadImage("Image//pinetop.png", gRenderer);
			pine4top.LoadImage("Image//pinetop.png", gRenderer);
			pine5top.LoadImage("Image//pinetop.png", gRenderer);


			SDL_Rect Rectpine1 = pine1.GetRect();
			SDL_Rect Rectpine2 = pine2.GetRect();
			SDL_Rect Rectpine3 = pine3.GetRect();
			SDL_Rect Rectpine4 = pine4.GetRect();
			SDL_Rect Rectpine5 = pine5.GetRect();

			SDL_Rect Rectpine1top = pine1top.GetRect();
			SDL_Rect Rectpine2top = pine2top.GetRect();
			SDL_Rect Rectpine3top = pine3top.GetRect();
			SDL_Rect Rectpine4top = pine4top.GetRect();
			SDL_Rect Rectpine5top = pine5top.GetRect();

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
				if (bird.cliiision() == true) {
					birddie.load("Audio//hit.wav");
					birddie.play();
					birddie.load("Audio//die.wav");
					birddie.play();
					SDL_Delay(500);
					quit = true;
				}








				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);


				gBackground.Render(gRenderer, NULL);

				if (xpine1 < -90)
				{
					xpine1 = 900;
					ypine1 = rand() % 130 + 60;

				}
				pine1.SetRect(xpine1 -= SCROLLING_SPEED, ypine1 + SPACE);
				Rectpine1.x = xpine1;
				Rectpine1.y = ypine1 + SPACE;
				pine1.Render(gRenderer, NULL);



				pine1top.SetRect(xpine1 -= SCROLLING_SPEED, ypine1 - PINE_H);
				Rectpine1top.x = xpine1;
				Rectpine1top.y = ypine1 - PINE_H;
				pine1top.Render(gRenderer, NULL);
				if (xpine2 < -90)
				{
					xpine2 = 900;
					ypine2 = rand() % 130 + 60;
				}


				pine2.SetRect(xpine2 -= SCROLLING_SPEED, ypine2 + SPACE);
				Rectpine2.x = xpine2;
				Rectpine2.y = ypine2 + SPACE;
				pine2.Render(gRenderer, NULL);

				pine2top.SetRect(xpine2 -= SCROLLING_SPEED, ypine2 - PINE_H);
				Rectpine2top.x = xpine2;
				Rectpine2top.y = ypine2 - PINE_H;
				pine2top.Render(gRenderer, NULL);


				if (xpine3 < -90)
				{
					xpine3 = 900;
					ypine3 = rand() % 130 + 60;
				}
				pine3.SetRect(xpine3 -= SCROLLING_SPEED, ypine3 + SPACE);
				Rectpine3.x = xpine3;
				Rectpine3.y = ypine3 + SPACE;
				pine3.Render(gRenderer, NULL);

				pine3top.SetRect(xpine3 -= SCROLLING_SPEED, ypine3 - PINE_H);
				Rectpine3top.x = xpine3;
				Rectpine3top.y = ypine3 - PINE_H;
				pine3top.Render(gRenderer, NULL);


				if (xpine4 < -90)
				{
					xpine4 = 900;
					ypine4 = rand() % 130 + 60;
				}
				pine4.SetRect(xpine4 -= SCROLLING_SPEED, ypine4 + SPACE);
				Rectpine4.x = xpine4;
				Rectpine4.y = ypine4 + SPACE;
				pine4.Render(gRenderer, NULL);

				pine4top.SetRect(xpine4 -= SCROLLING_SPEED, ypine4 - PINE_H);
				Rectpine4top.x = xpine4;
				Rectpine4top.y = ypine4 - PINE_H;
				pine4top.Render(gRenderer, NULL);


				if (xpine5 < -90)
				{
					xpine5 = 900;
					ypine5 = rand() % 130 + 60;
				}
				pine5.SetRect(xpine5 -= SCROLLING_SPEED, ypine5 + SPACE);
				Rectpine5.x = xpine5;
				Rectpine5.y = ypine5 + SPACE;
				pine5.Render(gRenderer, NULL);

				pine5top.SetRect(xpine5 -= SCROLLING_SPEED, ypine5 - PINE_H);
				Rectpine5top.x = xpine5;
				Rectpine5top.y = ypine5 - PINE_H;
				pine5top.Render(gRenderer, NULL);



				bird.render(gRenderer);

				bird.Movepine();
				bird.move(Rectpine1);
				bird.move(Rectpine2);
				bird.move(Rectpine3);
				bird.move(Rectpine4);
				bird.move(Rectpine5);

				bird.move(Rectpine1top);
				bird.move(Rectpine2top);
				bird.move(Rectpine3top);
				bird.move(Rectpine4top);
				bird.move(Rectpine5top);

				bird.move(gr);



				ground.Render(gRenderer, NULL);

				SDL_RenderPresent(gRenderer);






				SDL_Delay(50);

			}

			int pointgame = bird.Point();

			if (maxpoint < pointgame) maxpoint = pointgame;
			string Point = to_string(pointgame);
			string maxPoint = to_string(maxpoint);

			gBackground.Render(gRenderer, NULL);
			Game Score;
			Score.LoadImage("Image//score.png", gRenderer);
			Score.SetRect(364, 136);
			Score.Render(gRenderer, NULL);
			//
			SDL_Color color = { 141,136,117 };
			SDL_Surface* surface = TTF_RenderText_Solid(gFont, Point.c_str(), color);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);

			int texW = 0;
			int texH = 0;
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect dstrect = { 445, 200, texW, texH };
			SDL_RenderCopy(gRenderer, texture, NULL, &dstrect);
			//
			SDL_Surface* gsurface = TTF_RenderText_Solid(gFont, maxPoint.c_str(), color);
			SDL_Texture* gtexture = SDL_CreateTextureFromSurface(gRenderer, gsurface);
			SDL_Rect gdstrect = { 445, 280, texW, texH };
			SDL_RenderCopy(gRenderer, gtexture, NULL, &gdstrect);


			SDL_RenderPresent(gRenderer);
			SDL_Delay(1000);
			sound.stop();

		}
		quit2 = false;
		quit = false;


	}



	quitSDL(gWindow, gRenderer);
	return 0;
}


