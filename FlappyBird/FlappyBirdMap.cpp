
#include "FlappyBirdMap.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


void FlappyBirdMap::LoadMap()
{
    

    const int hang = 10;
    const int cot = 400;
    const int kc = 4;
    int arr[hang][cot] = {};
    srand(time(0));

    for (int i = 15; i < cot; i += 8) {
        int m = rand() % 6;
        arr[m][i] = 2;
        arr[m + kc][i] = 3;
        for (int j = 0; j < m; j++) {
            arr[j][i] = 1;
        }
        for (int j = m + kc + 1; j < hang; j++) {
            arr[j][i] = 5;
        }

    }
    for (int i = 15 + 4; i < cot; i += 8) {
        int m = rand() % 6 + 4;
        arr[m][i] = 3;
        arr[m - kc][i] = 2;
        for (int j = 0; j < m - kc; j++) {
            arr[j][i] = 1;
        }
        for (int j = m + 1; j < hang; j++) {
            arr[j][i] = 5;
        }

    }
    for (int i = 0; i < cot; i++) {
        arr[9][i] = 4;
    }
    





    for (int i = 0; i < MAX_MAP_Y; i++)
    {
        for (int j = 0; j < MAX_MAP_X; j++)
        {
            game_map_.tile[i][j] = arr[i][j];
            int val = game_map_.tile[i][j];
            if (val > 0)
            {
                if (j > game_map_.max_x_) game_map_.max_x_ = j;
                if (i > game_map_.max_y_) game_map_.max_y_ = i;
            }
        }
    }
    game_map_.max_x_ = (game_map_.max_x_ + 1) * TILE_SIZE;
    game_map_.max_y_ = (game_map_.max_y_ + 1) * TILE_SIZE;
    game_map_.start_x_ = 0;
    game_map_.start_y_ = 0;


}


void FlappyBirdMap::LoadTiles(SDL_Renderer* screen)
{
    char file_img[50];
    FILE* fp = NULL;
    for (int i = 0; i < MAX_TILES; i++)
    {
        sprintf_s(file_img, "Image/%d.png", i);

        fopen_s(&fp, file_img, "rb");
        if (fp == NULL)
        {
            continue;
        }

        fclose(fp);
        tile_mat[i].LoadImage(file_img, screen);

    }
}


void FlappyBirdMap::DrawMap(SDL_Renderer* screen)
{
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = game_map_.start_x_ / TILE_SIZE;

    x1 = (game_map_.start_x_ % TILE_SIZE) * -1;
    x2 = x1 + 900 + (x1 == 0 ? 0 : TILE_SIZE); //900=SCR_WEITH

    map_y = game_map_.start_y_ / TILE_SIZE;

    y1 = (game_map_.start_y_ % TILE_SIZE) * -1;
    y2 = y1 + 500 + (y1 == 0 ? 0 : TILE_SIZE);


    for (int i = y1; i < y2; i += TILE_SIZE)
    {
        map_x = game_map_.start_x_ / TILE_SIZE;
        for (int j = x1; j < x2; j += TILE_SIZE)
        {
            int val = game_map_.tile[map_y][map_x];

            if (val > 0)
            {
                tile_mat[val].SetRect(j, i);
                tile_mat[val].Render(screen);
               
            }
            map_x++;
        }
        map_y++;
    }
}