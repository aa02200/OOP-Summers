#include "Caravan.h"



Caravan::~Caravan()
{
    delete[]spriteClips;
}

Caravan::Caravan(LTexture* image, float x, float y):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[1];
    this->spriteSheetTexture = image;

     //Frame 0
    spriteClips[ 0 ].x = 10;
    spriteClips[ 0 ].y = 610;
    spriteClips[ 0 ].w = 113;
    spriteClips[ 0 ].h = 116;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
void Caravan::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Caravan::Move()
{
    x=x-2;
}
