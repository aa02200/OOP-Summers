#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "Character..h"
#include<string.h>
using namespace std;
class Word
{
private:
    Point position;  //declaring object
    LTexture* spriteSheetTexture;  //declaring pointer
    string String;  //declaring variable
    int sizeOfString;  //declaring variable
    Character* cha;  //declaring pointer
    int width;  //declaring variable
    int height;  //declaring variable
    int valx;
public:
    Word();
    Word(LTexture* image, float x, float y, string String);
    ~Word();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetSize();
    int GetX();
};
