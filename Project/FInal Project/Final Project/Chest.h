#ifndef CHEST_H
#define CHEST_H
#include"Unit.h"


class Chest:public Unit
{
    public:
        ~Chest();
        Chest(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();

    protected:

    private:
};

#endif // CHEST_H
