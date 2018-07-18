#include "MenuScreen.h"


MenuScreen::~MenuScreen()
{
    std::cout<<"Menu Screen deleted"<<std::endl;
    delete [] spriteClips;
}

MenuScreen::MenuScreen(LTexture* image, float x, float y):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[1];
    this->spriteSheetTexture = image;

    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = 800;
    spriteClips[0].h = 600;

    this->x = x;
    this->y = y;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
}

void MenuScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture -> Render( x - width/2, y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}
