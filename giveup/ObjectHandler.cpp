#include "ObjectHandler.h"
#include "Gameobject.h"


Gameobject* stadium;
Gameobject* rim;
Gameobject* bush;

Gameobject* player1;
Gameobject* player2;
Gameobject* player3;

Gameobject* ball1;



Gameobject* m1;
Gameobject* m3;
Gameobject* m5;
Gameobject* m7;
Gameobject* m9;
Gameobject* m11;
Gameobject* m13;
Gameobject* m15;


Gameobject* j;
Gameobject* j4;
Gameobject* j7;



ObjectHandler::ObjectHandler()
{
    stadium = new Gameobject("assets/backg.png", 0, 0, 16, 9, 0);
    rim = new Gameobject("assets/rim.png", 680, 150, 6, 7, 0);
    bush = new Gameobject("assets/bush.png", 940, 530, 1, 1, 0);
    player1 = new Gameobject("assets/p1.png", 150, 384, 2, 3, 0);
    player2 = new Gameobject("assets/p2.png", 150, 384, 2, 3, 0);
    player3 = new Gameobject("assets/p3.png", 150, 384, 2, 3, 0);

    ball1 = new Gameobject("assets/ball1.png", 245, 450, 1, 1, 0);
    /*ball2 = new Gameobject("assets/ball2.png", 245, 517, 1, 1, 0);
    ball3 = new Gameobject("assets/ball3.png", 245, 555, 1, 1, 0);*/

    m1 = new Gameobject("movesprite/m1.png", 156, 384, 2, 3, 0);
    /*m2 = new Gameobject("movesprite/m2.png", 156, 413, 2, 3, 0);*/
    m3 = new Gameobject("movesprite/m3.png", 156, 384, 2, 3, 0);
    /*m4 = new Gameobject("movesprite/m4.png", 156, 413, 2, 3, 0);*/
    m5 = new Gameobject("movesprite/m5.png", 156, 384, 2, 3, 0);
    /*m6 = new Gameobject("movesprite/m6.png", 156, 413, 2, 3, 0);*/
    m7 = new Gameobject("movesprite/m7.png", 156, 384, 2, 3, 0);
    /*m8 = new Gameobject("movesprite/m8.png", 156, 413, 2, 3, 0);*/
    m9 = new Gameobject("movesprite/m9.png", 156, 384, 2, 3, 0);
    /*m10 = new Gameobject("movesprite/m10.png", 156, 413, 1.1, 3, 0);*/
    m11 = new Gameobject("movesprite/m11.png", 156, 384, 1.2, 3, 0);
    /*m12 = new Gameobject("movesprite/m12.png", 156, 413, 2, 3, 0);*/
    m13 = new Gameobject("movesprite/m13.png", 156, 384, 2, 3, 0);
    /*m14 = new Gameobject("movesprite/m14.png", 156, 413, 2, 3, 0);*/
    m15 = new Gameobject("movesprite/m15.png", 156, 384, 2, 3, 0);
    /*m16 = new Gameobject("movesprite/m16.png", 156, 413, 2, 3, 0);*/

    j = new Gameobject("jump/j1.png", 156, 413, 2, 3, 0);
    /*j2 = new Gameobject("jump/j2.png", 156, 380, 2, 3, 0);
    j3 = new Gameobject("jump/j3.png", 156, 340, 2, 3, 0);*/
    j4 = new Gameobject("jump/j4.png", 156, 310, 2, 3, 0);
    /*j5 = new Gameobject("jump/j5.png", 156, 290, 2, 3, 0);
    j6 = new Gameobject("jump/j6.png", 156, 330, 2, 3, 0);*/
    j7 = new Gameobject("jump/j7.png", 156, 380, 1, 3, 0);
    /*j8 = new Gameobject("jump/j8.png", 156, 413, 2, 3, 0);*/
}

ObjectHandler::~ObjectHandler()
{
}

void ObjectHandler::updateObj(int factor, int k)
{
    stadium->updateBg();
    rim->update(0, 0);
    bush->update(0, 0);
    player1->update(factor, 0);
    player2->update(factor, 0);
    player3->update(factor, 0);
    factor = 0;

    ball1->updateBall(k);
    /*ball2->update(k, i);
    ball3->update(k, i);*/
    /*i += acos(0.0);*/

    m1->update(k, 0);
    /*m2->update(k);*/
    m3->update(k, 0);
    /*m4->update(k);*/
    m5->update(k, 0);
    /*m6->update(k);*/
    m7->update(k, 0);
    /*m8->update(k);*/
    m9->update(k, 0);
    /*m10->update(k);*/
    m11->update(k, 0);
    /*m12->update(k);*/
    m13->update(k, 0);
    /*m14->update(k);*/
    m15->update(k, 0);
    /*m16->update(k);*/

    j->update(k, 0);
    
    j4->update(k, 0);
    
    j7->update(k, 0);
    
}

void ObjectHandler::renderObj(int mflag, int enter)
{
    stadium->render();
    rim->render();
    bush->render();

    if (mflag == 0 && enter != 1)
    {
        if (SDL_GetTicks() % 4 == 0)
        {
            player1->render();
            ball1->render();
            SDL_Delay(50);
        }
        else if (SDL_GetTicks() % 4 == 1)
        {
            player2->render();
            ball1->render();
            SDL_Delay(50);
        }
        else if (SDL_GetTicks() % 4 == 2)
        {
            player3->render();
            ball1->render();
            SDL_Delay(50);
        }
        else if (SDL_GetTicks() % 4 == 3)
        {
            player2->render();
            ball1->render();
            SDL_Delay(50);
        }
    }
    else if (mflag == 1 && enter != 1)
    {
        if (SDL_GetTicks() % 8 == 0)
        {
            m1->render();
            ball1->render();
            SDL_Delay(100);
        }
       
        else if (SDL_GetTicks() % 8 == 1)
        {
            m3->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 2)
        {
            m5->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 3)
        {
            m7->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 4)
        {
            m9->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 5)
        {
            m11->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 6)
        {
            m13->render();
            ball1->render();
            SDL_Delay(100);
        }
        
        else if (SDL_GetTicks() % 8 == 7)
        {
            m15->render();
            ball1->render();
            SDL_Delay(100);
        }
        //factor += k;
    }
    else if (mflag == 2 && enter != 1)
    {
        if (SDL_GetTicks() % 3 == 0)
        {
            j->render();
            SDL_Delay(150);
        }
        
        else if (SDL_GetTicks() % 3 == 1)
        {
            j4->render();
            SDL_Delay(150);
        }
        
        else if (SDL_GetTicks() % 3 == 2)
        {
            j7->render();
            SDL_Delay(150);
        }
        
    }
    else if (enter == 1)
    {
        player1->render();
        ball1->render();
        SDL_Delay(1000);
    }
}

