/*
*******************************************************
✥ Title  :- Singly Linked List
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

int Menu();  // Menu Function Declaration

// Singly Linked List Class
class SLL
{
private:
   struct Node
   {
      int item;
      Node *next;
   };
   Node *head;

public:
   SLL() { head = NULL; }
   void InsertAtLast(int);
   void InsertAtBegin(int);
   void InsertAfter(int, int);
   void DeleteLast();
   void DeleteFirst();
   void DeleteNode(int);
   void ViewItem();
   ~SLL() 
   {
      while(head)
         DeleteFirst();
   }
};

// 1. Insert at last
void SLL::InsertAtLast(int data)
{
   Node *n = new Node;
   n->item = data;
   n->next = NULL;
   if(head == NULL)
      head = n;
   else
   {
      Node *temp;
      temp = head;
      while(temp->next!=NULL)
      {
         temp = temp->next;
      }
      temp->next = n;
   }
}

// 2. Insert at begin
void SLL::InsertAtBegin(int data)
{
   Node *n = new Node;
   n->item = data;
   n->next = NULL;
   if(head == NULL)
      head = n;
   else
   {
      n->next = head->next;
      head = n;  
   }
}

// 3. Insert after certain item.
void SLL::InsertAfter(int searchItem,int data)
{
   Node *temp;
   temp = head;
   while(temp!=NULL)
   {
      if(temp->item==searchItem)
         break;
      temp = temp->next;
   }
   if(temp!=NULL)
   {
      Node *n = new Node;
      n->item = data;
      n->next = temp->next;
      temp->next = n;
   }
}

// 4. Delete at last position.
void SLL::DeleteLast()
{
   if (head == NULL)
      cout << "There is nothing to delete" << endl;
   else
   {
      Node *temp1,*temp2;
      temp1 = head;
      temp2 = NULL;
      while(temp1!=NULL)
      {
         temp2 = temp1;
         temp1 = temp1->next;
      }
      temp2->next = NULL;
      delete temp1;
   }
}

// 5. Delete at first position.
void SLL::DeleteFirst()
{
   Node *temp;
   if(head == NULL)
      cout << "There is nothing to delete" << endl;
   else
   {
      temp = head;
      head = temp->next;
      delete temp;  
   }
}

// 6. Delete a particular item with searching.
void SLL::DeleteNode(int searchItem)
{
   Node *temp1,*temp2;
   temp1 = head;
   while(temp1!=NULL)
   {
      if(temp1->item==searchItem)
         break;
      temp2=temp1;
      temp1 = temp1->next;
   }
   if(temp1!=NULL)
   {
      if(temp1->next==NULL)
         DeleteLast();
      else if(temp1 == head)
         DeleteFirst();
      else
      {
         temp2->next=temp1->next;
         delete temp1;
      }
   }
}

// 7. View list item. 
void SLL::ViewItem()
{
   Node *temp;
   while(temp!=NULL)
   {
      cout << temp->item << " ";
      temp = temp->next;   
   }
}


// Menu Function.
int Menu()
{
   int choice;
   cout << "Welcome to Singly Linked List Program" << endl;
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
   SLL obj;
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