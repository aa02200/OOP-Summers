#ifndef ENDSCREEN_H
#define ENDSCREEN_H
#include"Unit.h"


class EndScreen:public Unit
{
    public:
        ~EndScreen();
        EndScreen(LTexture* image, float x, float y);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);

    protected:

    private:
};

#endif // ENDSCREEN_H
