#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Character
{
private:
    Point position;   //declaring object
    int character_value; //declaring variables
    int width;           //declaring variables
    int height;          //declaring variables
    SDL_Rect spriteClips; //declaring object
    LTexture* spriteSheetTexture; //declaring pointer
public:
    Character();
    Character(LTexture* image, float x, float y, char chara);
    ~Character();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};

