#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->unit->GetAlive() == false)
        {
            if(temp->prev == NULL)
            {
                head=head->next;
                if(head!=NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                temp = head;
            }
            else if(temp ->next == NULL)
            {
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                break;
            }
            else
            {
                Node* carry = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                temp = carry;
            }
        }
        temp = temp->next;
    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Render(frame, gRenderer, debug);
        temp=temp->next;
    }
}

void Queue::Move()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->unit->Move();
        temp=temp->next;
    }
}
