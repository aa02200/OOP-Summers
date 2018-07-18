#ifndef BANDIT_H
#define BANDIT_H
#include"Unit.h"
#include"Weapon.h"
#include"Bow.h"
#include"Dagger.h"

enum CURRENTWEAPON {DAGGER_,BOW_};
class Bandit:public Unit
{
    public:
        ~Bandit();
        Bandit(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);
        void Move();

    protected:

    private:
        int currentWeapon;
};

#endif // BANDIT_H
