#include"Rect.h"

Rect::Rect(SDL_Rect rect)
{
    this->fillRect = rect;
}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer)
{
    SDL_RenderFillRect( gRenderer, &(this->fillRect) );
}

