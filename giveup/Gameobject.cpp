#include "Gameobject.h"
#include "TextureManager.h"


int velY = 0;
int flag = 0;

Gameobject::Gameobject(const char* textsheet, int x, int y, float factor, int factory, int moveflag)
{
    // renderer = ren;
    objTexture = TextManager::LoadTexture(textsheet);
    xpos = x;
    ypos = y;
    f = factor;
    fy = factory;
    mf = moveflag;
}

Gameobject::~Gameobject()
{
}

void Gameobject::update(int k, double i)
{
    xpos = xpos + k;
    ypos = ypos + i;

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * f;
    destRect.h = srcRect.h * fy;
}

void Gameobject::updateBall(int k)
{
    xpos = xpos + k;
    if (ypos <= 545)
    {
        if (ypos == 540) { flag = 1; }
        if (ypos == 450) { flag = 0; }
        if (flag == 1)
        {
            velY = -15;
        }
        else
        {
            velY = 15;
        }
        ypos += velY;
    }

    srcRect.h = 64;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * f;
    destRect.h = srcRect.h * fy;

}

void Gameobject::updateBg()
{
    srcRect.h = 480;
    srcRect.y = 640;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 1000;
    destRect.h = 640;
}

void Gameobject::render()
{
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}