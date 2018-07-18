#include "Button.h"

Button::Button()
{
    width=64;  //initializing variable
    height=64;  //initializing variable
}

Button::~Button()
{
    //dtor
}

Button::Button(LTexture* image, float x, float y,string String)
{
    spriteSheetTexture = image;  //loading the image file
    word = Word(spriteSheetTexture, x, y, String);  //initialing object

    //frame for the first part of button
    spriteClips0.x = 0;
    spriteClips0.y = 440;
    spriteClips0.w = 64;
    spriteClips0.h = 64;

    //frame for the second part of button

    spriteClips1.x = 30;
    spriteClips1.y = 440;
    spriteClips1.w = 64;
    spriteClips1.h = 64;

    //frame for the third part of button

    spriteClips2.x = 89;
    spriteClips2.y = 440;
    spriteClips2.w = 64;
    spriteClips2.h = 64;

    position.x=x;
    position.y=y;

    this->width = spriteClips0.w;
    this->height = spriteClips0.h;

}

void Button:: Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    //displaying the first part of button

    spriteSheetTexture->Render( position.x - float((word.GetSize()-1)*64/2), position.y-height/2 , &spriteClips0, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - float((word.GetSize()-1)*64/2), position.y-height/2 , width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    for (int i = 1; i < word.GetSize()-2; i++)  //loop for the number of buttons displayed
    {
        //displaying the second part of button
        spriteSheetTexture->Render( position.x - float((word.GetSize()+1)*64/2) + i*64, position.y-height/2, &spriteClips1, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if(debug == true)
        {
            SDL_Rect rect = { position.x - float((word.GetSize()+1)*64/2) + i*64, position.y-height/2, width, height };
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            SDL_RenderDrawRect( gRenderer, &rect );
        }
    }

    //displaying the third part of button

    spriteSheetTexture->Render(  position.x + float((word.GetSize()-3)*64/2), position.y-height/2 , &spriteClips2, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = {  position.x + float((word.GetSize()-3)*64/2), position.y-height/2 , width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    word.Render(frame,gRenderer,debug);   //displaying the string to be printed on button

}
