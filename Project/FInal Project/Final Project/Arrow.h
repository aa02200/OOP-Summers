#ifndef ARROW_H
#define ARROW_H
#include"Weapon.h"
#include<math.h>


class Arrow : public Weapon
{
    public:
        ~Arrow();
        Arrow(LTexture*,float,float,double angle);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();
        void MissedMove();

    protected:

    private:
};

#endif // ARROW_H
