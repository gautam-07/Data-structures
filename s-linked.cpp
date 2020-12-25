// Singly Linked List for integers input.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class SLL
{
   private:
      struct node
      {
         int item;
         node *next;
      };
      node *start;
   public:
      SLL(){   start=NULL;}
      void InsertAtLast(int);
      void InsertAtFirst(int);
      void DeleteLast();
      void DeleteFirst();
      void ViewList();
};

void SLL::InsertAtLast(int data)
{
   node *n;
   n=(node*)malloc(sizeof(node));
   n->item=data;
   n->next=NULL;
   if(start==NULL)
      start=n;
   else
   {
      node *temp;
      temp=start;
      while(temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=n;
   }
}

void SLL::InsertAtFirst(int data)
{
   node *n;
   n=(node*)malloc(sizeof(node));
   n->item=data;
   n->next=start;
   start=n;
}

void SLL::DeleteLast()
{

}
