

#include "Game.h"

Game::Game()
{
	gTexture = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}

Game::~Game()
{
	Free();

}
bool Game::LoadImage(std::string path, SDL_Renderer* screen)
{
	SDL_Texture* new_texture = NULL;

	SDL_Surface* load_surface = NULL;

	load_surface = IMG_Load(path.c_str());

	if (load_surface != NULL)
	{

		SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
		new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
		if (new_texture != NULL)
		{
			rect_.w = load_surface->w;
			rect_.h = load_surface->h;

		}
		SDL_FreeSurface(load_surface);

	}
	gTexture = new_texture;
	return gTexture != NULL;
}

void Game::Render(SDL_Renderer* des, const SDL_Rect* clip/*=NULL*/)
{
	SDL_Rect renderquad = { rect_.x,rect_.y,rect_.w,rect_.h };

	SDL_RenderCopy(des, gTexture, clip, &renderquad);

}

void Game::Free()
{
	if (gTexture != NULL)
	{
		SDL_DestroyTexture(gTexture);
		gTexture = NULL;
		rect_.w = 0;
		rect_.h = 0;
	}
}


Audio::~Audio() {
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char* filename) {
	SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
	deviceId = SDL_OpenAudioDevice(nullptr, 0, &wavSpec, nullptr, 0);
}

void Audio::play() {
	SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
}

void Audio::stop() {
	SDL_PauseAudioDevice(deviceId, 1);
	//SDL_CloseAudioDevice(deviceId);
}
