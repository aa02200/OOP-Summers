#ifndef CARAVAN_H
#define CARAVAN_H
#include"Unit.h"


class Caravan:public Unit
{
    public:
        ~Caravan();
        Caravan(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();

    protected:

    private:
};

#endif // CARAVAN_H
