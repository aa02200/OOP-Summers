#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "Unit.h"
#include"Rastan.h"
#include"Bandit.h"
#include"Chest.h"
#include"Weapon.h"
#include"Bow.h"
#include"Arrow.h"
#include"Healer.h"
#include"Food.h"
#include"Dagger.h"
#include"Caravan.h"
#include"BloodSplash.h"
#include"Word.h"
#include<windows.h>
#include<mmsystem.h>

class GameScreen: public Unit
{
    public:
        void GameLoop(bool, string*);
        GameScreen(LTexture* image, float x, float y , LTexture*,LTexture*);
        ~GameScreen();
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void Render1(long int& frame, SDL_Renderer* gRenderer, bool debug, bool, string*);
        void MoveBackground();
        void RastanMove();
        void HealerMove();
        void FoodMove();
        void BowMove();
        void BanditMove();
        void CaravanMove();
        float getChest();
        bool Pick();
        void deleteHealer();
        void deleteFood();
        void deleteBow();
        bool ShowCaravan();
        int getOption();
        bool getCount();
        void fight1 (SDL_Renderer*);
        bool fightstart = false;
        bool dontMove;
        bool RastanHealth = false;
        bool RastanFood = false;
    private:
        long int blood_frame = 0;
        bool turn=true;
        bool pickObject = true;
        int currentWeapon = 0;
        bool caravanAlive = true;
        bool caravanReached = true;
        bool created = false;
        bool created1 = false;
        bool gene = false;
        int random;
        int coun = 0;
        int coun1 = 0;
        int option;
        Unit* rastan = NULL;
        Unit* chest = NULL;
        Unit* healer = NULL;
        Weapon* bow = NULL;
        Unit* food = NULL;
        Unit* caravan = NULL;
        Unit* bandit = NULL;
        Unit* bloodsplash = NULL;
        Unit* bloodsplash1 = NULL;
        Weapon* dagger1 = NULL;
        Weapon* dagger2 = NULL;
        Weapon* dagger1m = NULL;
        Weapon* dagger2m = NULL;
        Weapon* arrow1 = NULL;
        Weapon* arrow1m = NULL;
        Word* word =NULL;
        Word* word1 =NULL;
        Word* word2 =NULL;
        Word* word3 =NULL;
        Word* word4 =NULL;
        LTexture* spriteSheetTexture2;
        LTexture* spriteSheetTexture3;


};

#endif // GAMESCREEN_H
