#include "Bird.h"



LTexture::LTexture()
{
	
	mWidth = 0;
	mHeight = 0;
	
	xval = 0;
	yval = 0;
	xpos = 0;
	ypos = 0;

	onground = false;
}

LTexture::~LTexture() {

}

bool LTexture::loadFromFile(std::string path,SDL_Renderer* renderer)
{
	bool success = Game::LoadImage(path, renderer);
	if (success == true)
	{
		mWidth = rect_.w ;
		mHeight = rect_.h ;
	}

	return success;
}



void LTexture::render(SDL_Renderer* renderer)
{

	loadFromFile("Image//bird2.png", renderer);

	


	rect_.x = xpos;
	rect_.y = ypos;


	SDL_Rect* currentClip = NULL;
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { rect_.x ,rect_.y , mWidth, mHeight };

	//Set clip rendering dimensions
	if (currentClip != NULL)
	{
		renderQuad.w = currentClip->w;
		renderQuad.h = currentClip->h;
	}

	//Render to screen
	SDL_RenderCopy(renderer, gTexture, currentClip, &renderQuad);
	//Go to next frame
	
}
void LTexture::Inputkeyboard(SDL_Event e, SDL_Renderer* renderer)
{
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			status = JUMB_UP;
			input.up_ = 1;
		}
			break;
		}
	}
}


void LTexture::Player(Map& map_data)
{
	xval = 0;
	yval += GRAVITY_SPEED;

	if (yval >= MAX_SPEED) yval = MAX_SPEED;


	xpos += xval;
	ypos += yval;

	Checkmap(map_data);
}


void LTexture::Checkmap(Map& map_data)
{
	int x1 = 0;
	int x2 = 0;

	int y1 = 0;
	int y2 = 0;

	int height_min = mHeight < TILE_SIZE ? mHeight : TILE_SIZE;

	x1 = (xpos + xval) / TILE_SIZE;

	x2 = (xpos + xval + mWidth - 1) / TILE_SIZE;

	y1 = (ypos) / TILE_SIZE;
	y2 = (ypos + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (xval > 0)
		{
			if (map_data.tile[y1][x2] != 0 || map_data.tile[y2][x2] != 0)
			{
				xpos = x2 * TILE_SIZE;
				xpos = mWidth + 1;
				xval = 0;
			}
		}
	}



	int width_min = mWidth < TILE_SIZE ? mWidth : TILE_SIZE;
	x1 = (xpos) / TILE_SIZE;
	x2 = (xpos + width_min) / TILE_SIZE;

	y1 = (ypos + yval) / TILE_SIZE;
	y2 = (ypos + yval + mHeight - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_Y && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (yval > 0)
		{
			if (map_data.tile[y2][x1] != 0 || map_data.tile[y2][x2] != 0)
			{
				ypos = y2 * TILE_SIZE;
				ypos -= (mHeight + 1);
				yval = 0;
				onground = true;
			}
		}

	}
	ypos += yval;
}



		
	

