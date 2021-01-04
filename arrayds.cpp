/*
*******************************************************
✥ Title  :- Array Data Structure
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 30 December 2020
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

// Array Structure
struct Array
{
   int capacity;
   int lastIndex;
   int *ptr;  
};

// Function Declaration

Array* CreateArray(int);
void   Append(Array*,int);
void   ViewArray(Array*);
void   Insert(Array*,int,int);
void   Delete(Array*,int);
void   Edit(Array*,int,int);
int    Count(Array*);
int    Menu();

// Function Definition

// 1. Creating array data structure dynamically
Array* CreateArray(int cap) 
{
   Array *arr; 
   arr = new Array;
   arr->capacity = cap;
   arr->lastIndex = -1;
   arr->ptr = new int[cap];
   return arr;
}

// 2. Appending given item.
void Append(Array* arr, int data)
{
   if (arr->lastIndex+1 == arr->capacity)
   {
      cout << "Overflow" << endl;
   }
   else
   {
      arr->ptr[arr->lastIndex+1] = data;
      arr->lastIndex += 1;
   }
}

// 3. View Elements
void ViewArray(Array *arr)  
{
   int i;
   for (i=0;i<=arr->lastIndex;i++)
   {
      cout << arr->ptr[i] << " ";
   }
}

// 4. Count no of elements in array.
int Count(Array *arr)
{
   return arr->lastIndex+1;
}

// 5. Inserting data item at given index.
void Insert(Array* arr,int index, int data)
{
   if (index < 0 || index > arr->lastIndex+1)
      cout << "Invalid Index" << endl;

   else if (arr->lastIndex+1 == arr->capacity)
      cout << "Overflow" << endl;

   else
   {
      int i;
      for(i=arr->lastIndex; i>=index; i--)
      {
         arr->ptr[i+i] = arr->ptr[i];
      }
      arr->ptr[index] = data;
      arr->lastIndex += 1;
   }
}

// 6. Deleting an item at given index
void Delete(Array* arr,int index)
{
   if(index < 0 || index > arr->lastIndex)
      cout << "Invalid Index" << endl;
   else
   {
      int i;
      for(i=index; i<arr->lastIndex; i++)
      {
         arr->ptr[i] = arr->ptr[i+1];
      }
      arr->lastIndex -= 1;
   }
}

// 7. Editing an item
void Edit(Array* arr,int index, int data)
{
   if(index < 0 || index > arr->lastIndex)
      cout << "Invalid Index" << endl;
   else
   {
      arr->ptr[index] = data;
   }
   
}

// 8. Menu Function
int Menu()
{
   int choice;
   cout << "1. Create Array"   << endl;
   cout << "2. Append an item" << endl;
   cout << "3. Insert an item" << endl;
   cout << "4. Delete an item" << endl;
   cout << "5. Edit an item"   << endl;
   cout << "6. Exit" << endl;
   cout << "\n\nEnter your choice:- ";
   cin  >> choice;
   return choice;
}

// Main Function
int main()
{
   Array *arr;
   int cap,item,pos;
   int count = 0;
   while(1)
   {
      ViewArray(arr);
      system("clear");
      switch(Menu())
      {
         case 1:
            if(count == 0)
            {
               cout << "Enter the size of array you wanna create:- ";
               cin  >> cap;
               arr = CreateArray(cap);
               count++;
            }
            else if(count > 0)
            {
               cout << "Array is already created"<< endl;
            }
            break;
         case 2:
            cout << "Enter the item that you wanna append:- ";
            cin  >> item;
            Append(arr,item);
            break;
         case 3:
            cout << "Enter the index at which you wanna insert the item:- ";
            cin  >> pos;
            cout << "\nEnter the item that you wanna insert:- ";
            cin  >> item;
            Insert(arr,pos,item);
            break;
         case 4:
            cout << "Enter the index at which you wanna delete the item:-";
            cin  >> pos;
            Delete(arr,pos);
            break;
         case 5:
            cout << "Enter the index at which you wanna edit:- ";
            cin  >> pos;
            cout << "Enter the item to replace:- ";
            cin  >> item;
            Edit(arr,pos,item);
            break;
         case 6:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
}