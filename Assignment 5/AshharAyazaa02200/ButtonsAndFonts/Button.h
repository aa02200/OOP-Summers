#ifndef BUTTON_H
#define BUTTON_H
#include"Character.h"
#include "Word.h"
#include"string.h"


class Button
{
    private:
        Point position;  //declaring object
        SDL_Rect spriteClips0;  //declaring object
        SDL_Rect spriteClips1;  //declaring object
        SDL_Rect spriteClips2;  //declaring object
        LTexture* spriteSheetTexture;  //declaring pointer
        Word word;  //declaring object
        int height;  //declaring variable
        int width;  //declaring variable

    protected:

    public:
        Button();
        Button(LTexture* image, float x, float y, string String);
        ~Button();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
        void SetPosition(Point&);
        void SetPosition(int, int);

};

#endif // BUTTON_H
