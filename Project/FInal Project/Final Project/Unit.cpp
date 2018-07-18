#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{
    this->x = x;
    this->y = y;
    current_frame = 0;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
}


Unit::~Unit()
{
    //spriteSheetTexture = NULL;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move(int direction)
{

    if(direction==RIGHT)
    {
        speedx = 5;
    }

}

void Unit::Move()
{
     speedx = speedx * friction;
     speedy = speedy * friction;

     x = x + speedx;
     y = y + speedy;
}


int Unit::GetWidth()
{
    return width;
}

int Unit::GetHeight()
{
    return height;
}

float Unit::GetX()
{
    return x;
}
float Unit::GetY()
{
    return y;
}
void Unit::MissedMove()
{

}
