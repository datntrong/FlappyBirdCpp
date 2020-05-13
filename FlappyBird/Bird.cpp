#include "Bird.h"



LTexture::LTexture()
{
	
	mWidth = 0;
	mHeight = 0;
	
	mVelX = 0;
	mVelY = 0;
	mPosX = 0;
	mPosY = 0;

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


	rect_.x = mPosX -mapx_;
	rect_.y = mPosY -mapy_;
	
	
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

			case SDLK_SPACE:
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
	mVelX = mVelX;
	mVelX += SCROLLING_SPEED;;
	mVelY += GRAVITY_SPEED;

	if (mVelY >= MAX_SPEED) mVelY = MAX_SPEED;
	if (mVelX >= MAX_SCROLLING_SPEED) mVelX = MAX_SCROLLING_SPEED;
	
	mPosX += mVelX;
	mPosY += mVelY;

	

	if (input.up_ == 1) {
		mVelY = mVelY - JUMB_SPEED;
		
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

	x1 = (mPosX + mVelX) / TILE_SIZE;

	x2 = (mPosX + mVelX + mWidth - 1) / TILE_SIZE;

	y1 = (mPosY) / TILE_SIZE;
	y2 = (mPosY + height_min - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (mVelX > 0)
		{
			if (map_data.tile[y1][x2] != 0 || map_data.tile[y2][x2] != 0)
			{
				
				mPosX = x2 * TILE_SIZE;
				mPosX -= mWidth + 1;
				mVelX = 0;
				
				
				collision = true;
			}
		}
		else if (mVelX < 0)
		{
			if (map_data.tile[y1][x1] != 0 || map_data.tile[y2][x1] != 0)
			{
				mPosX = (x1 + 1) * TILE_SIZE;
				mVelX = 0;
				collision = true;
			}
		}
	}



	int width_min = mWidth < TILE_SIZE ? mWidth : TILE_SIZE;
	x1 = (mPosX) / TILE_SIZE;
	x2 = (mPosX + width_min) / TILE_SIZE;

	y1 = (mPosY + mVelY) / TILE_SIZE;
	y2 = (mPosY + mVelY + mHeight - 1) / TILE_SIZE;

	if (x1 >= 0 && x2 < MAX_MAP_Y && y1 >= 0 && y2 < MAX_MAP_Y)
	{
		if (mVelY > 0)
		{
			if (map_data.tile[y2][x1] != 0 || map_data.tile[y2][x2] != 0)
			{	
				
				mPosY = y2 * TILE_SIZE;
				mPosY -= (mHeight + 1);
				mVelY = 0;
				
				
				collision = true;
			}
		}
		else if (mVelY < 0)
		{
			if (map_data.tile[y1][x1] != 0 || map_data.tile[y1][x2] != 0)
			{
				mPosY = (y1 + 1) * TILE_SIZE;
				mVelY = 0;
				collision = true;
			}
		}

	}



	
}


void LTexture::ScrollingMap(Map& map_data)
{
	map_data.start_x_ = mPosX;
	map_data.start_y_ = 0;
}
		
	

