#pragma once

#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

class Gameobject
{
public:
    Gameobject(const char* texturesheet, int x, int y, float factor, int factory, int moveflag);
    ~Gameobject();

    void update(int k, double i);
    void updateBall(int k);
    void render();
    void updateBg();

    int xpos;
    int ypos;
    float f;
    int fy;
    int mf;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    // SDL_Renderer* renderer;

};
