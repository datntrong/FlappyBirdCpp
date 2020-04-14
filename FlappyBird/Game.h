#pragma once
#pragma once
#ifndef GAME_H
#define GAME_H
#include "Function.h"


class Game
{
public:
	Game();
	~Game();
	void SetRect(const int& x, int& y) {
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

#endif // !GAME_H

