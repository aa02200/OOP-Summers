#pragma once
#include"Node.h"

class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Clean();
    void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void Move();
};
