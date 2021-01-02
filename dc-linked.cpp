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
   Node *n = new Node;
   n->prev = NULL;
   n->item = data;
   n->next = NULL;
   if(head==NULL)
   {
      head = n;
      head->next = head;
   }
   else
   {
      n->next = head;
      head->prev = n;
      head = n;  
   }
}

// 2. Insert at Last
void DCLL::InsertAtLast(int data)
{
   Node *n = new Node;
   n->prev = NULL;
   n->item = data;
   n->next = NULL;
   if(head == NULL)
   {
      head = n;
      head->next = head;
   }
   else
   {
      Node *temp;
      temp=head;
      do
      {
         temp = temp->next;
      } while (temp->next!=head);
      n->next = head;
      n->prev = temp;
      temp->next = n;
   }
}


// 3. Insert after some element
void DCLL::InsertAfter(int searchItem, int data)
{
   Node *n = new Node;
   n->prev = NULL;
   n->item = data;
   n->next = NULL;
   Node *temp;
   temp=head;
   do
   {
      if(temp->item == searchItem)
         break;
      temp = temp->next;
   } while (temp->next!=head);

   if(temp->next==head)
   {
      n->next = head;
      n->prev = temp;
      temp->next = n;
   }
   else
   {
      temp->next->prev = n;
      n->next = temp->next;
      temp->next = n;
      n->prev = temp;  
   }
}

// 4. Delete first node
void DCLL::DeleteFirst()
{
   if(head!=NULL)
   {
      Node *temp;
      temp = head;
      temp->next->prev = NULL;
      head = temp->next;
      delete temp;
   }
}

// 5. Delete last node
void DCLL::DeleteLast()
{
   if(head!=NULL)
   {
      Node *temp;
      temp = head;
      do
      {
         temp = temp->next;
      } while (temp->next!=head);
      temp->prev->next = head;
      delete temp;
   }
}

// 6. Delete particular node
void DCLL::DeleteNode(int searchItem)
{
   Node *temp;
   temp = head;
   do
   {
      if(temp->item == searchItem)
         break;
      temp = temp->next;
   } while (temp->next!=head);

   if(temp == head)
      DeleteLast();
   
   else if(temp->prev == NULL)
      DeleteFirst();
   
   else
   {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      delete temp; 
   }
}

// View list items
void DCLL::ViewList()
{
   if(head!=NULL)
   {
      Node *temp;
      temp = head;
      do
      {
         cout << temp->item << " ";
         temp = temp->next;
      } while (temp->next!=head);
   }
}


// Menu function
int Menu()
{
   int choice;
   cout << "Welcome to Doubly Circular Linked List Program" << endl;
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
   DCLL obj;
   int item,pos;
   int search;
   while(1)
   {
      obj.ViewList();
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

