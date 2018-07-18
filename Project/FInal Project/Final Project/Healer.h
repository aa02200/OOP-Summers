#ifndef HEALER_H
#define HEALER_H
#include"Unit.h"


class Healer:public Unit
{
    public:
        ~Healer();
        Healer(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();

    protected:

    private:
};

#endif // HEALER_H
