#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Game.h"

class TextManager
{
    public:
        static SDL_Texture* LoadTexture(const char* filename);
        static void Draw(SDL_Texture*, SDL_Rect src, SDL_Rect dest);

};
