#include "Arrow.h"

Arrow::~Arrow()
{
    delete[]spriteClips;
}

Arrow::Arrow(LTexture* image, float x, float y,double angle):Weapon(image,x,y, angle)
{
    spriteClips = new SDL_Rect[1];
    this->spriteSheetTexture = image;
    speedx = 2;
    speedy = 2;
    friction = 0.85f;


     //Frame 0
    spriteClips[ 0 ].x = 111;
    spriteClips[ 0 ].y = 59;
    spriteClips[ 0 ].w = 57;
    spriteClips[ 0 ].h = 62;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
void Arrow::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ 0 ], this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
void Arrow::Move()
{
     if (angle==0)
     {
         x=x+2;
     }
     else if (angle==-180)
     {
         x=x-2;
     }
}
void Arrow::MissedMove()
{

     x = x + cos((angle/180)*M_PI)*speedx;
     y = y + sin((angle/180)*M_PI)*speedy;
}



