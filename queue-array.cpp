/*
*******************************************************
✥ Title  :- Queue implemented through Array
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 5 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>

using namespace std;

struct queue
{
   int capacity;
   int front,rear;
   int *ptr;
};

// Function declaration
queue* CreateQueue(int);
void   enqueue(queue*,int);
void   dequeue(queue*);
void   viewQueue(queue*);
int    Menu();


// Function definition
queue* CreateQueue(int cap)
{
   queue *n = new queue;
   n->capacity = cap;
   n->rear  = -1;
   n->front = -1;
   n->ptr   = new int[cap];
   return n;
}


void enqueue(queue *arr,int data)
{
   if(arr->front==0 && arr->rear+1==arr->capacity || arr->rear+1==arr->front)
      cout << "Overflow" << endl;
   else if(arr->rear==-1)
   {
      arr->front = 0;
      arr->rear  = 0;
      arr->ptr[arr->rear] = data;
   }
   else if(arr->capacity == arr->rear+1)
   {
      arr->rear = 0;
      arr->ptr[arr->rear] = data;
   }
   else
   {
      arr->rear += 1;
      arr->ptr[arr->rear] = data;
   }
}


void dequeue(queue *arr)
{
   if(arr->front == -1)
      cout << "Underflow" << endl;
   else if(arr->front == arr->rear)
   {
      arr->front = -1;
      arr->rear  = -1;
   }
   else if(arr->front == arr->capacity-1)
   {
      arr->front = 0;
   }
   else
   {
      arr->front++;
   }
}


void viewQueue(queue *arr)
{
   int i;
   for(i=0; i<=arr->rear ;i++)
      cout << arr->ptr[arr->rear] << " ";
}


int Menu()
{
   int choice;
   cout << "Welcome to Queue data structure - through linked list" << endl;
   cout << "\n1. Create queue" << endl;
   cout << "2. enqueue" << endl;
   cout << "3. dequeue" << endl;
   cout << "4. E.X.I.T" << endl;
   cin  >> choice;
   return choice;
}


int main()
{
   queue *arr;
   int item,size;
   while(1)
   {
      viewQueue(arr);
      system("cls");
      switch(Menu())
      {
         case 1:
            cout << "Enter the size of queue :- ";
            cin  >> size;
            arr = CreateQueue(size);
            break;
         case 2:
            cout << "Enter the item that you wanna insert :- ";
            cin  >> item;
            enqueue(arr,item);
            break; 
         case 3:
            dequeue(arr);
            break;
         case 4:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
}