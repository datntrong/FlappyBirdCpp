#pragma once
#pragma once
#ifndef GAME_H
#define GAME_H
#include "SDL_utils.h"


typedef struct Input
{

	int down_;
	int up_;
};



class Game
{
public:
	Game();
	~Game();
	void SetRect(const int& x, const int& y) {
		rect_.x = x, rect_.y = y;
	}
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetGame() const { return gTexture; }

	virtual bool LoadImage(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);

	void Free();
protected:
	SDL_Texture* gTexture;
	SDL_Rect rect_;
};


class Audio {
public:
	~Audio();
	void load(const char* filename);
	void play();
	void stop();
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceId;
};

#endif // !GAME_H

