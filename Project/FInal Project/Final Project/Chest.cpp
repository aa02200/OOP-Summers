#include "Chest.h"


Chest::~Chest()
{
    cout << "Chest has been deallocated" << endl;
    delete[]spriteClips;
}

Chest::Chest(LTexture* image, float x, float y):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[2];
    this->spriteSheetTexture = image;


     //Frame 0
    spriteClips[ 0 ].x = 1;
    spriteClips[ 0 ].y = 729;
    spriteClips[ 0 ].w = 29;
    spriteClips[ 0 ].h = 31;

    //Frame 1
    spriteClips[ 1 ].x = 34;
    spriteClips[ 1 ].y = 729;
    spriteClips[ 1 ].w = 29;
    spriteClips[ 1 ].h = 31;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}

void Chest::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture->Render( x - width/4, y - height/4, &spriteClips[ frame % 2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
void Chest::Move()
{
    x=x-2;
}
