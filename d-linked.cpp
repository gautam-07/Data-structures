/*
*******************************************************
✥ Title  :- Doubly Linked List
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 31 December 2020
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class DLL
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
   DLL() { head = NULL; }
   void InsertAtLast(int);
   void InsertAtBegin(int);
   void InsertAfter(int, int);
   void DeleteLast();
   void DeleteFirst();
   void DeleteNode(int);
   void ViewItem();
   ~DLL() 
   {
      while(head)
         DeleteFirst();
   }
};

// 1. Insert at last
void DLL::InsertAtLast(int data)
{
   Node *n = new Node;
   n->prev = NULL;
   n->item = data;
   n->next = NULL;
   if(head == NULL)
   { head = n;}
   else
   {
      Node *temp;
      temp = head;
      while(temp->next!=NULL)
      {
         temp = temp->next;
      }
      n->prev = temp;
      temp->next = n;
   }
}

// 2. Insert at Beginning
void DLL::InsertAtBegin(int data)
{
   Node *n = new Node;
   n->prev = NULL;
   n->item = data;
   n->next = head;
   if(head != NULL)
      head->prev=n;
   head = n;  
}

// 3. Insert after 
void DLL::InsertAfter(int searchItem, int data)
{
   Node *temp;
   temp = head;
   while(temp!=NULL)
   {
      if(temp->item == searchItem)
         break;
      temp = temp->next;
   }
   if(temp!=NULL)
   {
      Node *n = new Node;
      n->prev = temp;
      n->item = data;
      n->next = temp->next;
      if(temp->next!=NULL)
         temp->next->prev = n;
      temp->next = n;
   }
}

// 4. Delete at last
void DLL::DeleteLast()
{
   Node *temp;
   if(head != NULL)
   {
      temp = head;
      if(head->next == NULL)
         head = NULL;
      else
      {
         while(temp->next!=NULL)
         {
            temp = temp->next;
         }
         temp->prev->next = NULL;
      }
      delete temp;
   }
}

// 5. Delete at first
void DLL::DeleteLast()
{
   Node *temp;
   if (head != NULL)
   {
      temp = head;
      head = head->next;
      if(head!=NULL)
         head->prev = NULL;
      delete temp;
   }
}

// 6. Delete particular node
void DLL::DeleteNode(int searchItem)
{
   Node *temp;
   temp = head;
   while(temp!=NULL)
   {
      if(temp->item == searchItem)
         break;
      temp = temp->next;
   }
   if(temp!=NULL)
   {
      if(temp->prev==NULL)
         DeleteFirst();
      else if(temp->next==NULL)
         DeleteLast();
      else
      {
         temp->next->prev = temp->prev;
         temp->prev->next = temp->next;
         delete temp;
      }
   } 
}

// 7. View list items
void DLL::ViewItem()
{
   Node *temp;
   temp = head;
   while(temp)
   {
      cout << temp->item << " ";
      temp = temp->next;
   }
}


// Menu Function.
int Menu()
{
   int choice;
   cout << "Welcome to Doubly Linked List Program" << endl;
   cout << "\n1. Insert item at last" << endl;
   cout << "2. Insert item at beginning" << endl;
   cout << "3. Insert item at your choice" << endl;
   cout << "4. Delete item from last" << endl;
   cout << "5. Delete item from beginning" << endl;
   cout << "6. Delete specific item of your choice" << endl;
   cout << "7. E.X.I.T" << endl;
   cout << "\n\nEnter your choice:- "; 
   cin  >> choice;
   return choice;
}

// main function
int main()
{
   DLL obj;
   int item,pos;
   int search;
   while(1)
   {
      obj.ViewItem();
      system("clear");
      switch(Menu())
      {
         case 1:
            cout << "Enter the data that you wanna insert at last:- ";
            cin  >> item;
            obj.InsertAtLast(item);
            break;
         case 2:
            cout << "Enter the data that you wanna insert at beginning:- ";
            cin  >> item;
            obj.InsertAtBegin(item);
            break;
         case 3:
            cout << "Enter the item that you wanna insert after:- ";
            cin  >> search;
            cout << "Enter the data that you wanna insert:- ";
            cin  >> item;
            obj.InsertAfter(search,item);
            break;
         case 4:
            obj.DeleteLast();
            break;
         case 5:
            obj.DeleteFirst();
            break;
         case 6:
            cout << "Enter the item that you wanna delete:- ";
            cin  >> search;
            obj.DeleteNode(search);
            break;
         case 7:
            exit(0);
         default:
            cout << "Invalid choice" << endl;
      }
   }
   return 0;
}

