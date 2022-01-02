#include "Game.h"
#include "Gameobject.h"
#include "Map.h"
#include "ObjectHandler.h"

int k = 0;
int factor = 0;
int mflag = 0;
int enter = 0;

Map* map;
ObjectHandler* obj;

SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title,int xpos,int ypos,int width,int height, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title,xpos,ypos,width,height,0);
    }

    renderer = SDL_CreateRenderer(window,-1,0);
    if(renderer)
    {
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        isrunning = true;
    }
    else
    {
        isrunning = false;
    }


    obj = new ObjectHandler();

    map = new Map();

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    switch (event.type)
    {
        case SDL_QUIT:
            isrunning = false;
            break;
        case SDL_KEYDOWN:
            if(keystates[SDL_SCANCODE_LEFT])
            {
                k = -15;
                mflag = 1;
                break;
            }
            if(keystates[SDL_SCANCODE_RIGHT])
            {
                k = +15;
                mflag = 1;
                break;
            } 
            if( keystates[SDL_SCANCODE_UP] )
            {
                mflag = 2;
                break;
            }
            if(keystates[SDL_SCANCODE_KP_ENTER] )
            {
                enter = 1;
                break;
            }
        case SDL_KEYUP:
            k = 0;
            mflag = 0;
            break;
        default:
            break;
    }

}

void Game::update()
{
    obj->updateObj(factor, k);
    factor = 0;
}
void Game::render()
{
    SDL_RenderClear(renderer);
    obj->renderObj(mflag, enter);
    map->DrawMap();
    if (mflag == 1 && enter != 1)
    {
        factor += k;
    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
