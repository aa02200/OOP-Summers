#ifndef BOW_H
#define BOW_H
#include "Weapon.h"

class Bow:public Weapon
{
    public:
        ~Bow();
        Bow(LTexture*,float,float,double);
        void Render(long int&, SDL_Renderer*, bool);
        void Move();

    protected:

    private:
};
#endif
