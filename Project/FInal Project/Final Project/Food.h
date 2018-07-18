#ifndef FOOD_H
#define FOOD_H
#include"Unit.h"


class Food: public Unit
{
    public:
        ~Food();
        Food(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();

    protected:

    private:
};

#endif // FOOD_H
