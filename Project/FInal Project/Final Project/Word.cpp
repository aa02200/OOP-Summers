#include "Word.h"
using namespace std;

Word::Word()
{
    width = 44;      //initializing variable
    height = 48;     //initializing variable
}

Word::~Word()
{
    delete [] cha;
}
Word::Word(LTexture* image, float x, float y, string String)
{
    unsigned i;
    cha = new Character[String.size()];  //declaring a dynamic array of size of string
    this->String = String;
    sizeOfString = this->String.size();  //storing the size of string
    for ( i = 0; i < String.size(); i++)  //loop for the size of string to store character in a array
    {
        cha[i] = Character(image,(x - (sizeOfString * 44)/2 + (i * 44)),y,String[i]);  //storing character in array
    }
    valx= x - (sizeOfString * 44)/2 + (i * 44);


}
void Word::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    for (unsigned i = 0; i < String.size(); i++)  //running a loop
    {
        cha[i].Render(frame,gRenderer,debug);  //calling the renderer function of character
    }
}

int Word::GetSize()
{
    return sizeOfString;
}

int Word::GetX()
{
    return valx;
}
