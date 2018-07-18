#include "SplashScreen.h"


SplashScreen::~SplashScreen()
{
    std::cout<<"Splash Screen deleted"<<std::endl;
    delete [] spriteClips;
}

SplashScreen::SplashScreen(LTexture* image, float x, float y, LTexture* image2):Unit(image,x,y)
{
    spriteClips = new SDL_Rect[1];
    this->spriteSheetTexture = image;
    this->spriteSheetTexture2 = image2;
    word = new Word(spriteSheetTexture2, 400+ 50 , 300 - 100 , "RASTAN");

    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = 800;
    spriteClips[0].h = 600;

    this->x = x;
    this->y = y;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
}

void SplashScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    spriteSheetTexture -> Render( x - width/2, y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    word->Render(frame,gRenderer,false);
}
