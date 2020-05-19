#include "Bird.h"
Audio jump;



LTexture::LTexture()
{
	mCollider.w = 72;
	mCollider.h = 50;
	mWidth = 0;
	mHeight = 0;

	mVelX = 0;
	mVelY = 0;
	mPosX = 100;
	mPosY = 100;
	point = 0;
	frame = 0;
	mapx_ = 0;
	mapy_ = 0;
	collision = false;
	jump.load("Audio//wing.wav");
}

LTexture::~LTexture() {

}

bool LTexture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
	bool success = Game::LoadImage(path, renderer);
	if (success == true)
	{
		mWidth = rect_.w / WALKING_ANIMATION_FRAMES;
		mHeight = rect_.h;
	}

	return success;

}



void LTexture::render(SDL_Renderer* renderer)
{

	loadFromFile("Image//bird3.png", renderer);


	rect_.x = mPosX - mapx_;
	rect_.y = mPosY - mapy_;

	//Go to next frame
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
			status = JUMP_UP;
			input.up_ = 1;
		}
		break;

		case SDLK_SPACE:
		{
			status = JUMP_UP;
			input.up_ = 1;
		}
		break;
		}
	}
}



void LTexture::loadMedia() {
	gSpriteClips[0].x = 0;
	gSpriteClips[0].y = 0;
	gSpriteClips[0].w = BIRD_WIDTH;
	gSpriteClips[0].h = BIRD_HEIGHT;

	gSpriteClips[1].x = 72;
	gSpriteClips[1].y = 0;
	gSpriteClips[1].w = BIRD_WIDTH;
	gSpriteClips[1].h = BIRD_HEIGHT;

	gSpriteClips[2].x = 144;
	gSpriteClips[2].y = 0;
	gSpriteClips[2].w = BIRD_WIDTH;
	gSpriteClips[2].h = BIRD_HEIGHT;
}

void LTexture::Movepine() {
	mVelX = mVelX;

	mVelY += GRAVITY_SPEED;

	if (mVelY >= MAX_SPEED) mVelY = MAX_SPEED;

	if (input.up_ == 1) {
		mVelY = mVelY - JUMP_SPEED;
		input.up_ = 0;

		jump.play();


	}
	mPosX += mVelX;
	mCollider.x = mPosX;
	//Move the dot up or down
	mPosY += mVelY;
	mCollider.y = mPosY;
}


void LTexture::move(SDL_Rect& wall)
{

	if (checkCollision(wall)) collision = true;
	//If the dot collided or went too far to the left or right
	if ((mPosX < 0) || (mPosX + BIRD_WIDTH > SCREEN_WIDTH) || checkCollision(wall))
	{
		//Move back
		mPosX -= mVelX;
		mCollider.x = mPosX;
	}



	//If the dot collided or went too far up or down
	if ((mPosY < 0) || (mPosY + BIRD_WIDTH > SCREEN_HEIGHT) || checkCollision(wall))
	{
		//Move back
		mPosY -= mVelY;
		mCollider.y = mPosY;
	}

}


bool LTexture::checkCollision(SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = mCollider.x;
	rightA = mCollider.x + mCollider.w;
	topA = mCollider.y;
	bottomA = mCollider.y + mCollider.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}







