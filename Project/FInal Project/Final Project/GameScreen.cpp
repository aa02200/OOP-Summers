#include "GameScreen.h"
#include<fstream>
#include<sstream>
GameScreen::GameScreen(LTexture* image, float x, float y,LTexture* image2,LTexture* image3) :Unit(image,x,y)
{
    spriteClips = new SDL_Rect[1];

    this->spriteSheetTexture = image;
    this->spriteSheetTexture2 = image2;
    this->spriteSheetTexture3 = image3;
    rastan = new Rastan(image,210,500);

    spriteClips[0].x = 0;
    spriteClips[0].y = 2829;
    spriteClips[0].w = 800;
    spriteClips[0].h = 600;

    chest = NULL;

    this->x = x;
    this->y = y;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;
}

GameScreen::~GameScreen()
{
    cout << "Game screen has been deallocated" << endl;
    delete [] spriteClips;
}

void GameScreen::MoveBackground()
{
    if(spriteClips[0].x+800!=1020)
    {
        spriteClips[0].x+=1;

    }
    else
    {
        spriteClips[0].x=120;
        spriteClips[0].x+=1;
    }
}


void GameScreen::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{

}

void GameScreen::Render1(long int& frame, SDL_Renderer* gRenderer, bool debug, bool saved, string* arr)
{
    static bool music = true;
    if(music)
    {
        music = false;
        PlaySound(TEXT("F:\\University\\Summers\\Oop\\Assignment\\FInal Project\\Final Project\\BackgroundMusic\\Superboy.wav"), NULL, SND_ASYNC|SND_FILENAME);

    }
    static bool SavedDone = saved;
    static bool HealthAndFoodDone = saved;
    static bool CountChange = saved;

    if (blood_frame%60 ==0)
    {
        blood_frame = 0;
    }
    if (pickObject==true)
    {
        if (SavedDone)
        {
            stringstream convert(arr[1]);
            convert>>option;
            SavedDone = false;
        }
        else
        {
            option=rand()%4;
        }

        pickObject=false;
        created = false;
        created1= false;


    }
    spriteSheetTexture -> Render( x - width/2, y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { x - width/2, y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
    rastan->Render(frame,gRenderer,false);
    if (saved == true && HealthAndFoodDone == true)
    {
        int LoadedHealth;
        int LoadedFood;
        stringstream convert(arr[3]);
        convert>>LoadedHealth;
        stringstream convert1(arr[4]);
        convert1>>LoadedFood;
        rastan->SetHealth(LoadedHealth);
        rastan->SetFood(LoadedFood);
        HealthAndFoodDone = false;

    }


        SDL_Rect fillRect1 = {400,5,100,20};
        SDL_Rect fillRect = {400,5,20*rastan->GetFood(),20};
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF );
        SDL_RenderFillRect( gRenderer, &(fillRect) );
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer,&fillRect1);

        SDL_Rect fillRect2 = {600,5,100,20};
        SDL_Rect fillRect3 = {600,5,5*rastan->GetHealth(),20};
        SDL_SetRenderDrawColor( gRenderer,  0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( gRenderer, &(fillRect3) );
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer,&fillRect2);


    rastan->SetAlive(true);
    long int static_frame = 0;

    long int static_frame1 = 1;
    if (saved == true && CountChange==true)
    {
        int count2;
        stringstream convert(arr[2]);
        convert>>count2;
        coun = count2;
        CountChange = false;
    }
    if (chest != NULL && coun < 7 && rastan->GetHealth()  > 0 && rastan->GetFood() > 0)
    {

        if (chest->GetX() == 100)
        {
            if (option==0)
            {

                this->deleteHealer();
                rastan->SetHealth(20);
                coun++;
            }
            else if (option==1)
            {
                this->deleteFood();
                rastan->SetFood(6);
                coun++;
            }
            else if (option==2)
            {
                this->deleteBow();
                coun++;
            }
            else if (option==3)
            {
                delete chest;
                chest = NULL;
                delete bandit;
                bandit = NULL;
                delete arrow1;
                arrow1 = NULL;
                delete arrow1m;
                arrow1m = NULL;
                delete bow;
                bow = NULL;
                delete dagger1;
                dagger1 = NULL;
                delete dagger1m;
                dagger1m = NULL;
                delete dagger2m;
                dagger2m = NULL;
                delete dagger2;
                dagger2 = NULL;
                delete bloodsplash;
                bloodsplash = NULL;
                delete bloodsplash1;
                bloodsplash1 = NULL;
                coun ++;
            }
            pickObject = true;

            rastan->SetFood(rastan->GetFood()-1);
        }

        else
        {



            if (chest->GetX() <= 350)
            {
                if (option == 0)
                {

                    chest->Render(static_frame1, gRenderer, false);

                    if (healer!=NULL)
                    {
                        healer->Render(static_frame, gRenderer, false);
                        word->Render(frame,gRenderer,false);
                        ofstream readfile;
                        char filename[50] = "save.txt";
                        readfile.open(filename);
                        readfile<<"0"<<endl;
                        readfile<<option<<endl;
                        readfile<<coun<<endl;
                        readfile<<rastan->GetHealth()<<endl;
                        readfile<<rastan->GetFood()<<endl;
                        readfile<<healer->GetX()<<endl;
                        readfile<<healer->GetY()<<endl;
                        readfile<<chest->GetX()<<endl;
                        readfile<<chest->GetY()<<endl;
                        readfile.close();
                    }
                    fightstart = false;
                }
                else if (option == 1)
                {
                    chest->Render(static_frame1, gRenderer, false);
                    if (food!=NULL)
                    {

                        food->Render(static_frame, gRenderer, false);
                        word1->Render(frame,gRenderer,false);
                        ofstream readfile;
                        char filename[50] = "save.txt";
                        readfile.open(filename);
                        readfile<<"1"<<endl;
                        readfile<<option<<endl;
                        readfile<<coun<<endl;
                        readfile<<rastan->GetHealth()<<endl;
                        readfile<<rastan->GetFood()<<endl;
                        readfile<<food->GetX()<<endl;
                        readfile<<food->GetY()<<endl;
                        readfile<<chest->GetX()<<endl;
                        readfile<<chest->GetY()<<endl;
                        readfile.close();
                    }
                    fightstart = false;
                }
                else if (option == 2)
                {
                    chest->Render(static_frame1, gRenderer, false);
                    if (bow!=NULL)
                    {
                        bow->Render(static_frame, gRenderer, false);
                        word2->Render(frame,gRenderer,false);
                        ofstream readfile;
                        char filename[50] = "save.txt";
                        readfile.open(filename);
                        readfile<<"2"<<endl;
                        readfile<<option<<endl;
                        readfile<<coun<<endl;
                        readfile<<rastan->GetHealth()<<endl;
                        readfile<<rastan->GetFood()<<endl;
                        readfile<<bow->GetX()<<endl;
                        readfile<<bow->GetY()<<endl;
                        readfile<<chest->GetX()<<endl;
                        readfile<<chest->GetY()<<endl;
                        readfile.close();
                        currentWeapon =1;
                    }
                    fightstart = false;
                }
                else if (option == 3)
                {
                    if (bandit->GetAlive())
                    {
                        bandit->Render(frame,gRenderer,false);
                        word3->Render(frame,gRenderer,false);
                        dontMove = true;
                        if (fightstart == true)
                        {
                            this->fight1(gRenderer);
                        }

                    }
                }


            }
            else if (option==3)
            {
                bandit->Render(frame,gRenderer,false);
                ofstream readfile;
                char filename[50] = "save.txt";
                readfile.open(filename);
                readfile<<"4"<<endl;
                readfile<<option<<endl;
                readfile<<coun<<endl;
                readfile<<rastan->GetHealth()<<endl;
                readfile<<rastan->GetFood()<<endl;
                readfile<<bandit->GetX()<<endl;
                readfile<<bandit->GetY()<<endl;
                readfile<<chest->GetX()<<endl;
                readfile<<chest->GetY()<<endl;
                readfile.close();
            }

            else
            {
                chest->Render(static_frame, gRenderer, false);
                ofstream readfile;
                char filename[50] = "save.txt";
                readfile.open(filename);
                readfile<<"3"<<endl;
                readfile<<option<<endl;
                readfile<<coun<<endl;
                readfile<<rastan->GetHealth()<<endl;
                readfile<<rastan->GetFood()<<endl;
                readfile<<chest->GetX()<<endl;
                readfile<<chest->GetY()<<endl;
                readfile.close();
            }
        }


    }
    else if (!rastan->GetAlive())
    {
        std::cout<< "RASTAN DIED"<<std::endl;
    }
    if (caravan != NULL && coun1 <6)
    {
        if(caravan->GetX() == 250)
        {
            delete caravan;
            caravan = NULL;
            caravanReached = false;
        }
        else if( caravan->GetX() != 250 )
        {
            caravan->Render(frame,gRenderer,false);
            word4->Render(frame,gRenderer,false);
            ofstream readfile;
            char filename[50] = "save.txt";
            readfile.open(filename);
            readfile<<"5"<<endl;
            readfile<<option<<endl;
            readfile<<coun<<endl;
            readfile<<rastan->GetHealth()<<endl;
            readfile<<rastan->GetFood()<<endl;
            readfile<<caravan->GetX()<<endl;
            readfile<<caravan->GetY()<<endl;
            readfile.close();
        }

    }
    if (rastan->GetHealth()<= 0)
    {
        RastanHealth = true;
    }
    if (rastan->GetFood()<= 0)
    {
        RastanFood = true;
    }

}
void GameScreen::fight1(SDL_Renderer* gRenderer)
{
    long int static_frame=0;
    if (bandit->GetAlive())
    {
        if (turn)
        {
            if (!gene)
            {
                random = rand()%100;
                gene = true;
            }
            if (currentWeapon==0)
            {
                if (random<40)
                {
                    if (dagger1->GetX()<400)
                    {
                        dagger1->Render(static_frame,gRenderer,false);
                        dagger1->Move();
                        if (dagger1->GetX()>=350)
                        {
                            for (blood_frame=0; blood_frame<7; blood_frame++ )
                            {
                                bloodsplash->Render(blood_frame,gRenderer,false);
                                //SDL_Delay(20);
                            }
                            turn = false;
                            gene = false;
                            bandit->SetAlive(false);
                            fightstart = false;
                            dontMove = false;

                        }
                    }

                }
                else
                {
                    if (dagger1m->GetX()<400)
                    {
                        dagger1m->Render(static_frame,gRenderer,false);
                        dagger1m->MissedMove();
                        if (dagger1m->GetX()>=350)
                        {
                            turn = false;
                            gene = false;
                        }
                    }
                }
            }
            else
            {
                bow->Render(static_frame,gRenderer,false);
                if (random<70)
                {
                    if (arrow1->GetX()<400)
                    {
                        arrow1->Render(static_frame,gRenderer,false);
                        arrow1->MissedMove();
                        if (arrow1->GetX()>=350)
                        {
                            for (blood_frame=0; blood_frame<7; blood_frame++ )
                            {
                                bloodsplash1->Render(blood_frame,gRenderer,false);
                                SDL_Delay(20);
                            }
                            turn = false;
                            gene = false;
                            bandit->SetAlive(false);
                            fightstart = false;
                            dontMove = false;
                        }
                    }

                }
                else
                {
                    if (arrow1m->GetX()<400)
                    {
                        arrow1m->Render(static_frame,gRenderer,false);
                        arrow1m->MissedMove();
                        if (arrow1m->GetX()>=350)
                        {
                            turn = false;
                            gene = false;
                        }
                    }
                }
            }
        }
        else
        {
            if (!gene)
            {
                random=rand()%100;
                gene = true;
            }
            if (random<40)
            {
                if (dagger2->GetX()>160)
                {
                    dagger2->Render(static_frame,gRenderer,false);
                    dagger2->Move();
                    if (dagger2->GetX()<=210)
                    {
                        for (blood_frame=0; blood_frame<7; blood_frame++ )
                            {
                                bloodsplash1->Render(blood_frame,gRenderer,false);
                                SDL_Delay(20);
                            }
                        turn=true;
                        gene = false;
                        rastan->SetHealth(rastan->GetHealth()-3);
                        if (rastan->GetHealth()<=0)
                        {

                            rastan->SetAlive(false);
                        }
                    }
                }
            }
            else
            {
                if (dagger2m->GetX()>160)
                {
                    dagger2m->Render(static_frame,gRenderer,false);
                    dagger2m->MissedMove();
                    if (dagger2m->GetX()<=210)
                    {
                        turn=true;
                        gene=false;
                    }
                }
            }
        }
    }
}

void GameScreen::GameLoop(bool saved1, string* arr)
{
    static bool saved = saved1;

    if (created==false)
    {
        if(option == 0 )
        {
            if (saved && arr[0] == "0")
            {
                int arri[4];
                stringstream convert(arr[7]);
                convert>>arri[0];
                stringstream convert1(arr[8]);
                convert1 >> arri[1];
                stringstream convert2(arr[5]);
                convert2>>arri[2];
                stringstream convert3(arr[6]);
                convert3 >> arri[3];
                chest = new Chest(spriteSheetTexture, arri[0] , arri[1]);
                healer = new Healer(spriteSheetTexture, arri[2] , arri[3]);
            }
            else
            {

                chest = new Chest(spriteSheetTexture, 800 , 500);
                healer = new Healer(spriteSheetTexture, 800 , 470);
            }

            word = new Word(spriteSheetTexture3,450,200,"HEALERRECIEVED");

        }
        else if (option == 1)
        {
            if (saved && arr[0] == "1")
            {
                int arri[4];
                stringstream convert(arr[7]);
                convert>>arri[0];
                stringstream convert1(arr[8]);
                convert1 >> arri[1];
                stringstream convert2(arr[5]);
                convert2>>arri[2];
                stringstream convert3(arr[6]);
                convert3 >> arri[3];
                chest = new Chest(spriteSheetTexture, arri[0] , arri[1]);
                food = new Food(spriteSheetTexture, arri[2] , arri[3]);
            }
            else
            {
                    chest = new Chest(spriteSheetTexture, 800 , 500);
                    food = new Food(spriteSheetTexture, 800, 470);
            }

            word1 = new Word(spriteSheetTexture3, 400+ 50 , 300 - 100 , "FOODRECIEVED");
        }
        else if (option == 2)
        {
            if (saved && arr[0] == "2")
            {
                int arri[4];
                stringstream convert(arr[7]);
                convert>>arri[0];
                stringstream convert1(arr[8]);
                convert1 >> arri[1];
                stringstream convert2(arr[5]);
                convert2>>arri[2];
                stringstream convert3(arr[6]);
                convert3 >> arri[3];
                chest = new Chest(spriteSheetTexture, arri[0] , arri[1]);
                bow = new Bow(spriteSheetTexture, arri[2] , arri[3],0);
            }
            else
            {
                chest = new Chest(spriteSheetTexture, 800 , 500);
                bow = new Bow(spriteSheetTexture, 820, 470, 0);
            }


            word2 = new Word(spriteSheetTexture3, 400+ 50 , 300 - 100 , "BOWRECIEVED");
        }
        else if (option == 3)
        {
            if( saved && arr[0]=="4")
            {
                int arri[2];
                stringstream convert(arr[5]);
                convert>>arri[0];
                stringstream convert1(arr[6]);
                convert1>>arri[1];
                chest = new Chest(spriteSheetTexture, arri[0] , arri[1]);
                bandit = new Bandit(spriteSheetTexture, arri[0] , arri[1]);

            }
            else
            {
                chest = new Chest(spriteSheetTexture, 800 , 500);
                bandit = new Bandit(spriteSheetTexture, 800, 470);


            }
            word3 = new Word(spriteSheetTexture3, 400+ 50 , 300 - 100 , "FIGHT");
            bow = new Bow(spriteSheetTexture, 255, 530, 0);
            //bow1 = new Bow(spriteSheetTexture, 350, 470, -180);
            arrow1 = new Arrow(spriteSheetTexture2, 210, 500, 0);
            arrow1m = new Arrow(spriteSheetTexture2, 210, 500, -20);
            dagger1 = new Dagger(spriteSheetTexture, 210, 500, 0);
            dagger2 = new Dagger(spriteSheetTexture, 350, 500, -180);
            dagger1m = new Dagger(spriteSheetTexture, 210, 500, 0);
            dagger2m = new Dagger(spriteSheetTexture, 350, 500, -180);
            bloodsplash = new BloodSplash(spriteSheetTexture,210,500,0);
            bloodsplash1 = new BloodSplash(spriteSheetTexture,350,470,-180);
            bandit->SetAlive(true);
        }
        created=true;
    }
    if (created1==false)
    {
        if(coun == 7)
        {
            if (saved && arr[0] == "5")
            {
                int arri[2];
                stringstream convert(arr[5]);
                convert>>arri[0];
                stringstream convert1(arr[6]);
                convert1>>arri[1];
                caravan = new Caravan(spriteSheetTexture, arri[0] , arri[1]);
            }
            caravan = new Caravan(spriteSheetTexture, 800 , 500);
            word4 = new Word(spriteSheetTexture3, 450,200,"CARAVAN");
            caravanAlive = false;
        }
        created1 = true;
    }
    saved = false;
}
void GameScreen::RastanMove()
{
    rastan->Move(RIGHT);
}
void GameScreen::HealerMove()
{
    if (chest != NULL)
    {
        chest->Move();
    }
    if (healer != NULL)
    {
        healer->Move();
    }
}
void GameScreen::FoodMove()
{
    if (chest != NULL)
    {
        chest->Move();
    }
    if (food != NULL)
    {
        food->Move();
    }
}
void GameScreen::BowMove()
{
    if (chest != NULL)
    {
        chest->Move();
    }
    if (bow != NULL)
    {
        bow->Move();
    }
}

void GameScreen::CaravanMove()
{
    if (caravan != NULL)
    {
        caravan->Move();
    }
}

void GameScreen::BanditMove()
{
    if (chest!= NULL)
    {
        chest->Move();
    }
    if(bandit != NULL && bandit->GetX()>350)
    {
        bandit->Move();
    }
}

float GameScreen:: getChest()
{
    return chest->GetX();
}


bool GameScreen::Pick()
{
    return pickObject;
}

void GameScreen::deleteHealer()
{
    delete chest;
    delete healer;
    healer = NULL;
    chest = NULL;
}
void GameScreen::deleteFood()
{
    delete chest;
    delete food;
    food = NULL;
    chest = NULL;
}
void GameScreen::deleteBow()
{
    delete chest;
    delete bow;
    bow = NULL;
    chest = NULL;
}

int GameScreen::getOption()
{
    return option;
}

bool GameScreen::ShowCaravan()
{
    return caravanAlive;
}

bool GameScreen::getCount()
{
    return caravanReached;
}





