#include "Healer.h"


Healer::~Healer()
{
    delete[]spriteClips;
}
Healer::Healer(LTexture* image, float x, float y):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[1];
    this->spriteSheetTexture = image;

     //Frame 0
    spriteClips[ 0 ].x = 78;
    spriteClips[ 0 ].y = 1730;
    spriteClips[ 0 ].w = 29;
    spriteClips[ 0 ].h = 45;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}
void Healer::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
void Healer::Move()
{
    x=x-2;
}
