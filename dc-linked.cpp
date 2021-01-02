/*
*******************************************************
✥ Title  :- Doubly Circular Linked List
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 2 January 2020
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class DCLL
{
private:
   struct Node
   {
      Node *prev;
      int item;
      Node *next;
   };
   Node *head;

public:
   DCLL() { head = NULL; }
   void InsertAtBegin(int);
   void InsertAtLast(int);
   void InsertAfter(int, int);
   void DeleteFirst();
   void DeleteLast();
   void DeleteNode(int);
   void ViewList();
   ~DCLL()
   {
      while (head)
         DeleteFirst();
   }
};

int Menu();

// 1. Insert At Begin
void DCLL::InsertAtBegin(int data)
{
   
}