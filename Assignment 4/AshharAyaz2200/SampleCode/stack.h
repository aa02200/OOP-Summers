#include<iostream>
#pragma once
#include"Rect.h"
using namespace std ; //used for cin and cout commands

struct Node
{
    SDL_Rect data;   //creating an object
    Node* next;      //creating a pointer
    Node()           //creating a constructor
    {
        next = NULL;
    }
};

class Stack
{
private:
    Node* head;        //pointer of type node
public:
    Stack();           //constructor
    ~Stack();          //destructor
    void Push(SDL_Rect);    //Push function of stack
    SDL_Rect Pop();         //Pop function for stack
    void Show(SDL_Renderer* ); //Print function for stack
    void isEmpty();               //Function to check whether stack is empty or not

};
Stack::Stack()   //constructor called
{
    head = NULL;   //setting head value by default to NULL
}
Stack::~Stack()
{
    while (head != NULL)    //running the loop until head point to NULL
    {
        Pop();             //calling the Pop function
        cout<<"Node deleted"<<endl;
    }
}
void Stack::Push(SDL_Rect val) //Push function taking in arguments as an object
{

    if (head == NULL)
    {
        Node* temp = new Node;     //creating a new node
        temp->data = val;          //setting the value
        temp->next = NULL;         //pointing it towards nothing
        head = temp;               //pointing head towards the newly created node
    }
    else
    {
        Node* temp = new Node;     //creating a new node
        temp->data = val;          //setting the value
        temp->next = head;         //pointing the node towards head
        head = temp;               //setting head to new node
    }
}
SDL_Rect Stack::Pop()         //Pop function of the stack
{

    SDL_Rect val;             //creating an object
    if (head != NULL)
    {
        Node* temp;           //creating a empty node
        val = head->data;     //storing the value removed
        temp = head;          //pointing the empty node towards head
        head = head->next;    //creating the node pointed bu=y head as head
        delete temp;          //deleting the empty node
    }
    return val;

}
void Stack::Show(SDL_Renderer* gRenderer)
{
    Node* temp = head;           //creating a empty node and pointing it towards head
    while(temp != NULL)          //condition until head is NULL
    {
        cout << &(temp->data)<<endl;
        SDL_RenderFillRect(gRenderer, &(temp->data));  //displaying the rectangles on the screen
        temp = temp->next;   //declaring current node as next of current node
    }
}
void Stack::isEmpty()
{
    while(head != NULL)  //until the stack gets empty
    {
        Pop();             //calling the Pop function
    }
}


