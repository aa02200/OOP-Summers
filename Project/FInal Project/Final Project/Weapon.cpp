#include "Weapon.h"


Weapon::Weapon(LTexture* image, float x, float y, double angle):Unit(image, x, y)
{
    cout<< "Weapon Created" << endl;
    this->angle = angle;
}

Weapon::~Weapon()
{
    cout << "Weapon Deallocated" << endl;
}
