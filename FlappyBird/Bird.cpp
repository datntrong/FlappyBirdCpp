#include "Bird.h"



LTexture::LTexture()
{
	
	mWidth = 0;
	mHeight = 0;
	
	xval = 0;
	yval = 0;
	xpos = 0;
	ypos = 0;

	frame = 0;
	mapx_ = 0;
	mapy_ = 0;
	collision = false;
}

LTexture::~LTexture() {

}

bool LTexture::loadFromFile(std::string path,SDL_Renderer* renderer)
{
	bool success = Game::LoadImage(path, renderer);
	if (success == true)
	{
		mWidth = rect_.w / WALKING_ANIMATION_FRAMES;
		mHeight = rect_.h ;
	}

	return success;
}



void LTexture::render(SDL_Renderer* renderer)
{

	loadFromFile("Image//bird3.png", renderer);


	rect_.x = xpos -mapx_;
	rect_.y = ypos -mapy_;
	
	
	frame++;
	if (frame >= 3) frame = 0;
	

	SDL_Rect* currentClip = &gSpriteClips[frame];
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
	

	//Cycle animation
	
	
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

void LTexture::loadMedia() {
	if (mWidth > 0 && mHeight > 0)
	{

		for (int i = 0; i < WALKING_ANIMATION_FRAMES; i++)
		{
			gSpriteClips[i].x = i*mWidth;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = mWidth;
			gSpriteClips[i].h = mHeight;
		}

		

	}
}


void LTexture::Player(Map& map_data)
{
	xval += SCROLLING_SPEED;;
	yval += GRAVITY_SPEED;

	if (yval >= MAX_SPEED) yval = MAX_SPEED;
	if (xval >= MAX_SCROLLING_SPEED) xval = MAX_SCROLLING_SPEED;
	
	xpos += xval;
	ypos += yval;

	

	if (input.up_ == 1) {
		yval = yval - JUMB_SPEED;
		
		input.up_ = 0;
	}

	

	Checkmap(map_data);
	ScrollingMap(map_data);
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
				xpos -= mWidth + 1;
				xval = 0;
				
				
				collision = true;
			}
		}
		else if (xval < 0)
		{
			if (map_data.tile[y1][x1] != 0 || map_data.tile[y2][x1] != 0)
			{
				xpos = (x1 + 1) * TILE_SIZE;
				xval = 0;
				collision = true;
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
				
				
				collision = true;
			}
		}
		else if (yval < 0)
		{
			if (map_data.tile[y1][x1] != 0 || map_data.tile[y1][x2] != 0)
			{
				ypos = (y1 + 1) * TILE_SIZE;
				yval = 0;
				collision = true;
			}
		}

	}



	
}


void LTexture::ScrollingMap(Map& map_data)
{
	map_data.start_x_ = xpos;
	map_data.start_y_ = 0;
}
		
	

