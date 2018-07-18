#pragma once
#include "Unit.h"
#include"Weapon.h"
#include"Bow.h"
#include"Dagger.h"

enum CURRENT_WEAPON {DAGGER,BOW};
class Rastan:public Unit

{
private:
protected:
    //enum ANIMATION_FRAMES {MAIN_OBJECT = 3};
    //SDL_Rect spriteClips[3];
    //LTexture* spriteSheetTexture;
    int currentWeapon;
    int health = 20;
    int food = 5;


public:
    Rastan();
    Rastan(LTexture* image, float x, float y);
    virtual ~Rastan();
    virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    int GetHealth();
    int GetFood();
    void SetHealth(int);
    void SetFood(int);
};

