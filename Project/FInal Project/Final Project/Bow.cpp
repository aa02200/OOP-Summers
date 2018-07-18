#include "Bow.h"
#include "Weapon.h"

Bow::~Bow()
{
    cout<<"Bow deallocated" << endl;
    delete[]spriteClips;
}

Bow::Bow(LTexture* image, float x, float y,double angle):Weapon(image, x, y, angle)
{
    spriteClips = new SDL_Rect[15];
    this->spriteSheetTexture = image;

    //First 6 frames
    for (int i = 0; i < 6; i++)
    {
        spriteClips[ i ].x = (70*i);
        spriteClips[ i ].y = 760;
        spriteClips[ i ].w = 70;
        spriteClips[ i ].h = 92;
    }

    //Last 6 frames
    for (int j = 6; j < 12; j++)
    {
        spriteClips[ j ].x =(70*j);
        spriteClips[ j ].y = 852;
        spriteClips[ j ].w = 70;
        spriteClips[ j ].h = 92;
    }
    //Frame 12
    spriteClips[ 12 ].x = 210;
    spriteClips[ 12 ].y = 760;
    spriteClips[ 12 ].w = 70;
    spriteClips[ 12 ].h = 92;

    //Frame 13
    spriteClips[ 13 ].x = 140;
    spriteClips[ 13 ].y = 760;
    spriteClips[ 13 ].w = 70;
    spriteClips[ 13 ].h = 92;


    //Frame 14
    spriteClips[ 14 ].x = 0;
    spriteClips[ 14 ].y = 760;
    spriteClips[ 14 ].w = 68;
    spriteClips[ 14 ].h = 92;


    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
}

void Bow::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    if(frame% 25 == 0)
    {
        current_frame++;
    }
    if (frame == 0)
    {
        current_frame = 0;
    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ current_frame % 15 ], this->angle, NULL, SDL_FLIP_NONE, gRenderer, 0.7 );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
void Bow::Move()
{
    x=x-2;
}

