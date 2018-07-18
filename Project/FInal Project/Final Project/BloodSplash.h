#ifndef BLOODSPLASH_H
#define BLOODSPLASH_H
#include"Unit.h"
#include"Word.h"


class BloodSplash:public Unit
{
    public:
        ~BloodSplash();
        BloodSplash(LTexture*,float,float,double);
        void Render(long int&, SDL_Renderer*, bool);

    protected:

    private:
        double angle;
        int current_frame = 0;
};

#endif // BLOODSPLASH_H
