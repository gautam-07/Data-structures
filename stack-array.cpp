/*
*******************************************************
✥ Title  :- Stack implemented through array
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 4 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct stack
{
   int capacity;
   int top;
   int *ptr;
};

stack* CreateStack(int);
void   push(stack*,int);
void   pop(stack*);
void   viewStack(stack*);
int    Menu();

stack* CreateStack(int size)
{
   stack *n = new stack;
   n->capacity = size;
   n->top = -1;
   n->ptr = new int[size];
   return n;
}

void push(stack *arr,int data)
{
   if(arr->top+1==arr->capacity)
      cout << "Overflow";
   else
   {
      arr->ptr[arr->top+1] = data;
      arr->top += 1;
   }
}

void pop(stack *arr)
{
   if(arr->top!=-1)
   {
      arr->ptr[arr->top+1] = arr->ptr[arr->top];
      arr->top -= 1;
   }
}

void viewStack(stack* arr)
{
   if(arr->top!=-1)
   {
      int i;
      for(i=0; i<arr->top; i++)
         cout << arr->ptr[i] << " ";
   }
}

int Menu()
{
   int choice;
   cout << "Welcome to Stack data structure - Through Array" << endl;
   cout << "\n1.Create stack" << endl;
   cout << "2. push.." << endl;
   cout << "3. pop.." << endl;
   cout << "4. E.X.I.T" << endl;
   cin  >> choice;
   return choice;
}

int main()
{
   stack *arr;
   int cap,item;
   while(1)
   {
      viewStack(arr);
      system("cls");
      switch(Menu())
      {
         case 1:
            cout << "Enter the size of stack you want :- ";
            cin  >> cap;
            CreateStack(cap);
            break;
         case 2:
            cout << "Enter the data that you wanna push :- ";
            cin  >> item;
            push(arr,item);
            break;
         case 3:
            pop(arr);
            break;
         case 4:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
}