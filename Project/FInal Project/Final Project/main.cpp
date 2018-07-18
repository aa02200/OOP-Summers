#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Unit.h"
#include"Rastan.h"
#include"Bandit.h"
#include"Word.h"
#include"SplashScreen.h"
#include"MenuScreen.h"
#include"GameScreen.h"
#include"Chest.h"
#include"Weapon.h"
#include"Bow.h"
#include"Arrow.h"
#include"Healer.h"
#include"Food.h"
#include"Dagger.h"
#include"EndScreen.h"
#include"Caravan.h"
#include"BloodSplash.h"
#include <windows.h>
#include <fstream>
#include <mmsystem.h>
char file[50] = "save.txt";
ifstream readfile;

string* Load(ifstream& readfile)
{
    string data;
    int line =0;
    string* arr;
    while(getline(readfile,data))
    {
        line++;
        if(line==1)
        {
            if (data == "0")
            {
                arr = new string[9];
            }
            if (data == "1")
            {
                arr = new string [9];
            }
            if (data == "2")
            {
                arr = new string [9];
            }
            if (data == "3")
            {
                arr = new string [7];
            }
            if (data == "4")
            {
                arr = new string [9];
            }
            if (data == "5")
            {
                arr = new string [7];
            }
            arr[0] = data;
        }


        arr[line-1]= data;

    }
    return arr;

}


//Pre defined screen width and height
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;
LTexture gWord;
LTexture gSplashScreen;
LTexture gMenuScreen;
LTexture gGameScreen;
LTexture gArrow;

string* arr;
int state;
bool fighting = true;
bool saved = false;
bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{

    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {

            bool quit = false;                     //Main loop flag
            SDL_Event e;                            //Event handler

            long int frame = 0;                     //Current animation frame
            srand (time(NULL));

            Word* word1 = NULL;
            Word* word2 = NULL;
            Word* word3 = NULL;
            Word* word11 = NULL;
            Word* word21 = NULL;
            Word* word31 = NULL;
            Word* word4 = new Word(&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) - 100, "WON");
            Word* word5 = new Word(&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) - 100, "LOST");
            SplashScreen* ss = NULL;
            MenuScreen* ms= NULL;
            GameScreen* gs = new GameScreen(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2,&gArrow,&gWord);
            EndScreen* es =  new EndScreen(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
            int x;
            int y;


            while( !quit )                          //While application is running
            {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                SDL_RenderClear( gRenderer );
                if (state == 0)
                {
                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\BackgroundMusic\\Superboy.wav"), NULL, SND_ASYNC|SND_FILENAME);
                    ss = new SplashScreen(&gSplashScreen, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2,&gWord);
                    ss->Render(frame,gRenderer,false);
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(5000);
                    state ++;
                }

                if (state == 1)
                {
                    ms = new MenuScreen(&gMenuScreen, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
                    ms->Render(frame,gRenderer,false);
                    word1 = new Word(&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) - 100, "START");
                    word2 = new Word (&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2 ), "LOAD");
                    word3 = new Word (&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) + 100, "QUIT");
                    if (x >320 && x<532  && y>181 && y<229)
                    {
                        gWord.SetColor(0,0,0);
                        word1->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word2->Render(frame,gRenderer,false);
                        word3->Render(frame,gRenderer,false);


                    }
                    else if (x >337 && x<508  && y>277 && y<318)
                    {
                        gWord.SetColor(0,0,0);
                        word2->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word1->Render(frame,gRenderer,false);
                        word3->Render(frame,gRenderer,false);

                    }
                    else if (x >339 && x<511  && y>380 && y<418)
                    {
                        gWord.SetColor(0,0,0);
                        word3->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word1->Render(frame,gRenderer,false);
                        word2->Render(frame,gRenderer,false);

                    }

                    else
                    {
                        gWord.SetColor(255,255,255);
                        word1->Render(frame,gRenderer,false);
                        word2->Render(frame,gRenderer,false);
                        word3->Render(frame,gRenderer,false);
                    }
                    SDL_RenderPresent( gRenderer );

                }

                if (state == 2)
                {
                    gs->Render1(frame,gRenderer,false, saved, arr);
                    Word word4 (&gWord, 130, 20, "PAUSE");
                    word4.Render(frame,gRenderer,false);
                    gs->GameLoop(saved, arr);
                    SDL_RenderPresent( gRenderer );
                    if (gs->getCount() == false)
                    {
                        state = 3;
                    }
                    if (gs->RastanHealth == true)
                    {

                        state = 5;
                    }
                    if (gs->RastanFood == true)
                    {
                        state = 5;
                    }



                }
                if (state == 3)
                {
                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\Applause.wav"), NULL, SND_ASYNC|SND_FILENAME);
                    es->Render(frame,gRenderer,false);
                    word4->Render(frame, gRenderer,false);
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(3000);
                    state = 1;
                    delete gs;
                    gs = new GameScreen(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2,&gArrow,&gWord);
                }
                if (state == 4)
                {
                    ms = new MenuScreen(&gMenuScreen, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
                    ms->Render(frame,gRenderer,false);
                    word11 = new Word(&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) - 100, "RESUME");
                    word21 = new Word (&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2 ), "MAINMENU");
                    word31 = new Word (&gWord, ((float)SCREEN_WIDTH / 2) + 50, ((float)SCREEN_HEIGHT / 2) + 100, "QUIT");
                    if (x >320 && x<532  && y>181 && y<229)
                    {
                        gWord.SetColor(0,0,0);
                        word11->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word21->Render(frame,gRenderer,false);
                        word31->Render(frame,gRenderer,false);

                    }
                    else if (x >337 && x<508  && y>277 && y<318)
                    {
                        gWord.SetColor(0,0,0);
                        word21->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word11->Render(frame,gRenderer,false);
                        word31->Render(frame,gRenderer,false);

                    }
                    else if (x >339 && x<511  && y>380 && y<418)
                    {
                        gWord.SetColor(0,0,0);
                        word31->Render(frame,gRenderer,false);
                        gWord.SetColor(255,255,255);
                        word11->Render(frame,gRenderer,false);
                        word21->Render(frame,gRenderer,false);

                    }

                    else
                    {
                        gWord.SetColor(255,255,255);
                        word11->Render(frame,gRenderer,false);
                        word21->Render(frame,gRenderer,false);
                        word31->Render(frame,gRenderer,false);
                    }
                    SDL_RenderPresent( gRenderer );


                }
                if (state == 5)
                {
                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\dun_dun.wav"), NULL, SND_ASYNC|SND_FILENAME);
                    es->Render(frame,gRenderer,false);
                    word5->Render(frame, gRenderer,false);
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(3000);
                    state = 1;
                    delete gs;
                    gs = new GameScreen(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2,&gArrow,&gWord);
                }

                while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                {
                    SDL_GetMouseState( &x, &y );
                    //User requests quit
                    if (state == 1)
                    {
                        if(e.type == SDL_MOUSEBUTTONDOWN)
                        {
                           if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (x >320 && x<532  && y>181 && y<229)
                                {
                                    delete gs;
                                    gs = new GameScreen(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2,&gArrow,&gWord);
                                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                    PlaySound(NULL,0,0);
                                    state = 2;
                                }

                            }
                            if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (x >339 && x<511  && y>380 && y<418)
                                {
                                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                    quit = true;
                                }

                            }
                            if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                if (x >337 && x<508  && y>277 && y<318)
                                {
                                    PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                    readfile.open(file);
                                    arr = Load(readfile);
                                    saved = true;
                                    state=2;
                                    readfile.close();

                                }

                            }
                        }



                    }
                    if (state == 2)
                    {
                        if (e.button.button==SDL_BUTTON_LEFT)
                        {
                            if (x >0 && x<208  && y>0 && y<37 && e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                state = 4;

                            }

                        }

                    }
                    if (state == 4)
                    {
                        if (e.type == SDL_MOUSEMOTION)
                        {
                            SDL_GetMouseState( &x, &y );
                        }

                        if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            SDL_GetMouseState( &x, &y );
                            if (x >320 && x<532  && y>181 && y<229)
                            {
                                PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                state = 2;
                            }

                        }
                        if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            SDL_GetMouseState( &x, &y );
                            if (x >339 && x<511  && y>380 && y<418)
                            {
                                PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                quit = true;
                            }

                        }
                        if (e.button.button==SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            SDL_GetMouseState( &x, &y );
                            if (x >337 && x<508  && y>277 && y<318)
                            {
                                PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\SoundEffects\\buttonclick.wav"), NULL, SND_SYNC|SND_FILENAME);
                                state = 1;
                            }

                        }


                    }

                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }


                }


                if(state == 2)
                {


                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
                    if (currentKeyStates[ SDL_SCANCODE_SPACE ])
                    {
                        gs->fightstart = true;
                    }

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                        if (!(gs->dontMove))
                            gs->MoveBackground();
                        gs->RastanMove();
                        if (gs->getOption()==0)
                        {
                            gs->HealerMove();
                        }
                        else if (gs->getOption()==1)
                        {
                            gs->FoodMove();
                        }
                        else if (gs->getOption()==2)
                        {
                            gs->BowMove();
                        }
                        else if (gs->getOption()==3)
                        {
                            if (!(gs->dontMove))
                                gs->BanditMove();

                        }
                        if (gs->ShowCaravan()==false)
                        {
                            gs->CaravanMove();
                        }

                        if (!(gs->dontMove))
                            frame++;
                    }
                }





                //	SDL_RenderPresent( gRenderer );     //Update screen

                if (frame % 60 == 0)
                {
                    frame = 0;
                }



            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load Music
    //Load sprite sheet texture
    if( !gSpriteSheetTexture.LoadFromFile( "image/collage.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gWord.LoadFromFile( "image/fontSprite.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gSplashScreen.LoadFromFile( "image/Rastan.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gMenuScreen.LoadFromFile( "image/mainbackground.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gGameScreen.LoadFromFile( "image/collage.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    if( !gArrow.LoadFromFile( "image/arrow.png", gRenderer  ) )
    {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded images
    gSpriteSheetTexture.Free();

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
