#ifndef WEAPON_H
#define WEAPON_H
#include "Unit.h"

class Weapon:public Unit
{
    public:
        Weapon();
        ~Weapon();
        Weapon(LTexture* image, float x, float y,double angle);


    protected:
        double angle = 0;

    private:
};

#endif // WEAPON_H
