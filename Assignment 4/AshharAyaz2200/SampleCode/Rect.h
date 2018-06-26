#pragma once
#include"SDL.h"
#include"Point.h"
#include <SDL_image.h>
/** Rect class **/

class Rect
{
private:
    SDL_Rect fillRect;
    Point topLeft;
    Point bottomRight;
public:

    Rect(SDL_Rect);
    void Draw(SDL_Renderer*);
};

