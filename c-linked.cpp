/*
*******************************************************
✥ Title  :- Circular Linked List
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 2 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class CLL
{
private:
   struct Node
   {
      int item;
      Node *next;
   };
   Node *last;

public:
   CLL() { last = NULL; }
   void InsertAtLast(int);
   void InsertAtBegin(int);
   void InsertAfter(int, int);
   void DeleteLast();
   void DeleteFirst();
   void DeleteNode(int);
   void ViewItems();
   ~CLL()
   {
      while (last)
         DeleteLast();
   }
};

int Menu();

// 1. Insert at beginning
void CLL::InsertAtBegin(int data)
{
   Node *n = new Node;
   n->item = data;
   n->next = NULL;
   if(last==NULL)
   {
      last = n;
      last->next = last;
   }
   else
   {
      n->next = last->next;
      last->next = n;
   }
}

// 2. Insert at last
void CLL::InsertAtLast(int data)
{
   Node *n = new Node;
   n->item = data;
   n->next = NULL;
   if(last==NULL)
   {
      last = n;
      last->next = last;
   }
   else
   {
      Node *temp;
      temp = last;
      n->next = last->next;
      temp->next = n;
      last = n;
   } 
}

// 3. Insert after particular node
void CLL::InsertAfter(int searchItem,int data)
{
   Node *temp;
   temp =  last;
   do
   {
      if(temp->item == searchItem)
         break;
      temp = temp->next;
   } while (temp!=last->next);

   if(temp==last)
      InsertAtLast(data);
   else if(temp== last->next)
      InsertAtBegin(data);
   else
   {
      Node *n = new Node;
      n->item = data;
      n->next = temp->next;
      temp = n;
   }
}

// 4. Delete first node
void CLL::DeleteFirst()
{
   if(last!=NULL)
   {
      Node *temp;
      temp = last->next;
      last->next = temp->next;
      delete temp;
   }
}

// 5. Delete Last Node
void CLL::DeleteLast()
{
   if(last!=NULL)
   {
      Node *temp1,*temp2;
      temp1 = last->next;
      temp2 = NULL;
      do
      {
         temp2 = temp1;
         temp1 = temp1->next;
      } while (temp1!=last->next);
      last = temp2;
      temp2->next = temp1->next;
      delete temp1; 
   }
}

// Delete particular node
void CLL::DeleteNode(int searchItem)
{
   Node *temp1,*temp2;
   temp1 =  last;
   temp2 = NULL;
   do
   {
      if(temp1->item == searchItem)
         break;
      temp2 = temp1;
      temp1 = temp1->next;
   } while (temp1!=last->next);
   if(temp1==last)
      DeleteLast();
   else if(temp1==last->next)
      DeleteFirst();
   else
   {
      temp2->next = temp1->next;
      delete temp1;
   }
}


// 7. View List Items
void CLL::ViewItems()
{
   if(last!=NULL)
   {
      Node* temp;
      temp = last->next;
      do
      {
         cout << temp->item << " ";
         temp = temp->next;  
      }while(temp!=last->next);
   }
}

// Menu function
int Menu()
{
   int choice;
   cout << "Welcome to Circular Linked List Program" << endl;
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
   CLL obj;
   int item,pos;
   int search;
   while(1)
   {
      obj.ViewItems();
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



