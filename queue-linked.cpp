/*
*******************************************************
✥ Title  :- Queue implemented through linked list
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 5 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Queue
{
private:
   struct node
   {
      int item;
      node *next;
   };
   node *start;

public:
   Queue() { start = NULL; }
   void enqueue(int);
   void dequeue();
   void viewQueue();
   ~Queue()
   {
      while (start)
         dequeue();
   }
};


void Queue::enqueue(int data)
{
   node *n = new node;
   n->item = data;
   n->next = NULL;
   if(start == NULL)
      start = n;
   else
   {
      node *temp;
      temp = start;
      n->next = temp->next;
      start = n;
   }
}


void Queue::dequeue()
{
   if(start!=NULL)
   {
      node *temp1,*temp2;
      temp1 = start;
      temp2 = NULL;
      while(temp1->next!=NULL)
      {
         temp2 = temp1;
         temp1 = temp1->next;
      }
      temp2->next = NULL;
      delete temp1;
   }
}

void Queue::viewQueue()
{
   node *temp;
   temp = start;
   while(temp)
   {
      cout << temp->item << " ";
      temp = temp->next;
   }
}


int Menu()
{
   int choice;
   cout << "Welcome to Queue data structure - through linked list" << endl;
   cout << "\n1. enqueue" << endl;
   cout << "2. dequeue" << endl;
   cout << "3. E.X.I.T" << endl;
   cin  >> choice;
   return choice;
}


int main()
{
   Queue obj;
   int item;
   while(1)
   {
      obj.viewQueue();
      system("cls");
      switch(Menu())
      {
         case 1:
            cout << "Enter the item that you wanna insert :- ";
            cin  >> item;
            obj.enqueue(item);
            break;
         case 2:
            obj.dequeue();
            break;
         case 3:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
} 