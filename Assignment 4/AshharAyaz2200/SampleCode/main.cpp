/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include"Rect.h"
#include"stack.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );


			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	Stack stk;   //creating object
	Stack stk1;  //creating object
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		if( !loadMedia() )  //Load media
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			bool quit = false;  //Main loop controller

			SDL_Event e;        //Event handler that takes care of all events

			bool mouseClicked = false;
			SDL_Rect fillRect;
			int oldx = 0;
            int oldy = 0;

            Rect* rect = NULL;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                    {
                        //Get mouse position
                        int x, y;
                        SDL_GetMouseState( &x, &y );

                        if(e.type ==  SDL_MOUSEMOTION)
                        {
                            if(mouseClicked == true)
                                fillRect = { oldx , oldy , x - oldx, y - oldy };
                        }

                        if(e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            if (e.button.button == SDL_BUTTON_LEFT )
                            {
                                if(mouseClicked == false)
                                {
                                    mouseClicked = true;
                                    oldx = x;
                                    oldy = y;
                                }
                            }
                            if (e.button.button == SDL_BUTTON_RIGHT) //condition to check when right mouse button clicked
                            {
                                stk1.Push(stk.Pop());  //removing the element from primary stack and storing it in secondary stack
                            }
                            SDL_RenderPresent( gRenderer );

                            if (e.button.button == SDL_BUTTON_MIDDLE) //condition to check when middle mouse button clicked
                            {
                                stk.Push(stk1.Pop());  //removing element from secondary stack and storing it in primary stack
                            }
                            SDL_RenderPresent( gRenderer );


                        }

                        if(e.type == SDL_MOUSEBUTTONUP  && e.button.button == SDL_BUTTON_LEFT)
                        {
                            if ((oldx - x) != 0 && (oldy - y) != 0 )  //condition to check if there is change in position then draw a rectangle
                            {
                                mouseClicked = false;
                                rect = new Rect(fillRect); //making a new rectangle
                                stk.Push(fillRect);    //storing the rectangle in primary stack
                                stk1.isEmpty();        //calling the empty function of stack

                            }

                        }

                    }
				}
                //Clear screen

                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

                if (rect != NULL)
                {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                }
                stk.Show(gRenderer);  //displaying the primary stack


				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close();

	return 0;
}
