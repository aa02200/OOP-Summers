#include "BloodSplash.h"

BloodSplash::~BloodSplash()
{
    delete[]spriteClips;
}

BloodSplash::BloodSplash(LTexture* image, float x, float y,double angle):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[7];

    this->spriteSheetTexture = image;


     //Frame 0
    spriteClips[ 0 ].x = 55;
    spriteClips[ 0 ].y = 40;
    spriteClips[ 0 ].w = 26;
    spriteClips[ 0 ].h = 25;

    spriteClips[ 1 ].x = 56;
    spriteClips[ 1 ].y = 279;
    spriteClips[ 1 ].w = 33;
    spriteClips[ 1 ].h = 25;

    spriteClips[ 2 ].x = 55;
    spriteClips[ 2 ].y = 364;
    spriteClips[ 2 ].w = 92;
    spriteClips[ 2 ].h = 60;

    spriteClips[ 3 ].x = 31;
    spriteClips[ 3 ].y = 484;
    spriteClips[ 3 ].w = 120;
    spriteClips[ 3 ].h = 88;

    spriteClips[ 4 ].x = 20;
    spriteClips[ 4 ].y = 1125;
    spriteClips[ 4 ].w = 132;
    spriteClips[ 4 ].h = 99;

    spriteClips[ 5 ].x = 6;
    spriteClips[ 5 ].y = 1245;
    spriteClips[ 5 ].w = 144;
    spriteClips[ 5 ].h = 109;

    spriteClips[ 6 ].x = 55;
    spriteClips[ 6 ].y = 40;
    spriteClips[ 6 ].w = 26;
    spriteClips[ 6 ].h = 25;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
void BloodSplash::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if(frame% 40  == 0)
    {
        current_frame++;
    }
    if (frame == 0)
    {
        current_frame = 0;
    }
    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ current_frame % 7 ], this->angle, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

