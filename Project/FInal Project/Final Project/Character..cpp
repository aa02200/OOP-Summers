#include"Character..h"
#include<iostream>

Character::Character()
{
    width = 44;      //initializing variable
    height = 48;     //initializing variable
    character_value = 0;  //initializing variable
}

Character::Character(LTexture* image, float x, float y, char chara)
{
    spriteSheetTexture = image;  //loading the file
    character_value = (int) chara;  //converting character to int

    //Frame 0
    if (character_value > 64 && character_value < 76)  //condition for alphabets
    {
        int multiplier = (character_value - 65) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 0;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 75 && character_value < 87)  //condition for alphabets
    {
        int multiplier = (character_value - 76) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 48;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 86 && character_value < 91)  ////condition for alphabets
    {
        int multiplier = (character_value - 87) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 96 && character_value < 104)  //condition for alphabets
    {
        int multiplier = ((character_value - 97) * 44) + 44 * 4;
        spriteClips.x = multiplier;
        spriteClips.y = 96;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 103 && character_value < 115)  //condition for alphabets
    {
        int multiplier = (character_value - 104) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 144;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 114 && character_value < 123)  //condition for alphabets
    {
        int multiplier = (character_value - 115) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 47 && character_value < 51)  //condition for alphabets
    {
        int multiplier = ((character_value - 48) * 44) + 8 * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 192;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }
    if (character_value > 50 && character_value < 58)  //condition for alphabets
    {
        int multiplier = (character_value - 51) * 44;
        spriteClips.x = multiplier;
        spriteClips.y = 240;
        spriteClips.w = 44;
        spriteClips.h = 48;
    }


    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

Character::~Character()
{
    char n = character_value + 97;
   // std::cout<<"\nCharacter "<<n<<" Destroyed";
}

void Character::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Character::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Character::SetPosition(int x, int y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Character::GetFrameWidth()
{
    return width;
}
int Character::GetFrameHeight()
{
    return height;
}

