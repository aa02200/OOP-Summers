#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include "Unit.h"

class MenuScreen:public Unit
{
    public:
        ~MenuScreen();
        MenuScreen(LTexture* image, float x, float y);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    private:
};

#endif // SPLASHSCREEN_H
