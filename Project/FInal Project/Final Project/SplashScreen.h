#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include "Unit.h"
#include"Word.h"

class SplashScreen:public Unit
{
    public:
        ~SplashScreen();
        SplashScreen(LTexture* image, float x, float y,LTexture*);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    private:
        LTexture* spriteSheetTexture2;
        Word* word = NULL;
};

#endif // SPLASHSCREEN_H
