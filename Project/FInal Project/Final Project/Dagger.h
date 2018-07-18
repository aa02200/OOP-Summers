#ifndef DAGGER_H
#define DAGGER_H
#include"Weapon.h"
#include<math.h>


class Dagger :public Weapon
{
    public:
        ~Dagger();
        Dagger(LTexture*,float,float,double angle);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();
        void MissedMove();

    protected:

    private:
};

#endif // DAGGER_H
