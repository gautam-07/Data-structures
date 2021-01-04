/*
*******************************************************
✥ Title  :- Stack implemented through linked list
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 4 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Stack_linked
{
private:
   struct node
   {
      int item;
      node *next;
   };
   node *start;

public:
   Stack_linked() { start = NULL; }
   void push(int);
   void pop();
   void viewStack();
   ~Stack_linked()
   {
      while (start)
         pop();
   }
};

int Menu();

void Stack_linked::push(int data)
{
   node *n = new node;
   n->item = data;
   n->next = NULL;
   if(start == NULL)
      start = n;
   else
   {
      n->next = start->next;
      start = n;
   }
}

void Stack_linked::pop()
{
   if(start != NULL)
   {
      node *temp;
      temp = start;
      start = temp->next;
      delete temp;
   }
}

void Stack_linked::viewStack()
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
   cout << "Welcome to Stack data structure - Through linked list" << endl;
   cout << "\n1. push.." << endl;
   cout << "2. pop.." << endl;
   cout << "3. E.X.I.T" << endl;
   cin  >> choice;
   return choice;
}


int main()
{
   Stack_linked obj;
   int item;
   while(1)
   {
      obj.viewStack();
      switch(Menu())
      {
         case 1:
            cout << "Enter the item that you wanna push :- ";
            cin  >> item;
            obj.push(item);
            break;
         case 2:
            obj.pop();
            break;
         case 3:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;  
}

