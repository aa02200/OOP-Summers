#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
    protected:
        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction
        long int current_frame = 0;

        //enum ANIMATION_FRAMES {FLYING_FRAMES = 3};
        //SDL_Rect spriteClips[ FLYING_FRAMES ];
        //LTexture* spriteSheetTexture;

    public:
        Unit(LTexture* image, float x, float y);
        Unit();
        virtual ~Unit();
        void SetAlive(bool);
        bool GetAlive();
        int GetWidth();
        int GetHeight();
        SDL_Rect* spriteClips;
        LTexture* spriteSheetTexture;
        float GetX();
        float GetY();
        virtual void SetHealth(int){};
        virtual void SetFood(int){};
        virtual int GetHealth(){return 0;};
        virtual int GetFood(){return 0;};
        virtual void Move(int direction);
        virtual void Move();
        virtual void MissedMove();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug) = 0 ;
};



