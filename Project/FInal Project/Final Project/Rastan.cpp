#include "Rastan.h"
#include "Unit.h"
#include <iostream>

using namespace std;


Rastan::~Rastan()
{
    cout<<"Rastan Deallocated"<<endl;
    delete[]spriteClips;
}

Rastan::Rastan(LTexture* image, float x, float y):Unit(image, x, y)
{
    spriteClips = new SDL_Rect[3];
    spriteSheetTexture = image;
    currentWeapon=DAGGER;


    //Frame 0
    spriteClips[ 0 ].x = 150;
    spriteClips[ 0 ].y = 2394;
    spriteClips[ 0 ].w = 40;
    spriteClips[ 0 ].h = 40;

    //Frame 1
    spriteClips[ 1 ].x = 150;
    spriteClips[ 1 ].y = 2440;
    spriteClips[ 1 ].w = 40;
    spriteClips[ 1 ].h = 40;

    //Frame 2
    spriteClips[ 2 ].x = 150;
    spriteClips[ 2 ].y = 2536;
    spriteClips[ 2 ].w = 40;
    spriteClips[ 2 ].h = 40;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

}

void Rastan::Move()
{
     y = y - 20;
     if (y < -100)
     {
         SetAlive(false);
     }
}

void Rastan::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if(frame% 25 == 0)
    {
        current_frame++;
    }
    if (frame == 0)
    {
        current_frame = 0;
    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ current_frame % 3 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer , 1.5);
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

 void Rastan::SetHealth(int val)
 {
     health = val;
 }
 int Rastan::GetHealth()
 {
     return health;
 }
 int Rastan::GetFood()
 {
     return food;
 }
 void Rastan::SetFood(int val)
 {
     food = val;
 }


