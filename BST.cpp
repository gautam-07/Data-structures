/*
*******************************************************
✥ Title  :- Binary Search Tree
✥ Author :- Gautam Khatter 🧐
✥ Date   :- 16 January 2021
*******************************************************
✥ This Data Structure is made for integer input only.
*******************************************************
*/


#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{
   node *left;
   int item;
   node *right;
};

// Function Declaration

int Insert(node **, int);
void InOrder(node *);
void PreOrder(node *);
void PostOrder(node *);
int Menu();



// Function Definition
void InOrder(node *root)
{
   if(root)
   {
      InOrder(root->left);
      cout << root->item << " ";
      InOrder(root->right);
   }
}


void PreOrder(node* root)
{
   if (root)
   {
      cout << root->item << " ";
      PreOrder(root->left);
      PreOrder(root->right);
   }
}


void PostOrder(node *root)
{
   if (root)
   {
      PostOrder(root->left);
      PostOrder(root->right);
      cout << root->item << " ";
   }
}


int Insert(int data,node **root)
{
   node *n = new node;
   node *temp;
   n->left = NULL;
   n->right = NULL;
   n->item = data;
   if (*root == NULL)
   {
      *root = n;
      return 1;
   }
   else
   {
      temp = *root;
      while(1)
      {
         if (temp->item == data)
         {
            return 0;
         }
         else if (data < temp->item)
         {
            if (temp->left == NULL)
            {
               temp->left = n;
               return 1;
            }
            temp = temp->left;
         }
         else
         {
            if (temp->right == NULL)
            {
               temp->right = n;
               return 1;
            }
            temp = temp->right;
         }
      } 
   }
}



// Menu Function
int Menu()
{
   int choice;
   cout << "Welcome To Binary Search Tree Program" << endl;
   cout << "\n\n1. Insert In The Tree" << endl;
   cout << "2. InOrder Traversal Of The Tree" << endl;
   cout << "3. PreOrder Traversal Of The Tree" << endl;
   cout << "4. Postorder Traversal Of The Tree" << endl;
   cout << "5. Delete From Tree" << endl;
   cout << "6. E.X.I.T" << endl;
   cin >> choice;
   return choice;
}

// Main Function
int main()
{
   node *root = NULL;
   int data;
   while (1)
   {
      switch(Menu())
      {
         case 1:
            cout << "Enter the data that you wanna insert ";
            cin >> data;
            if(Insert(&root,data))
               cout << "Data Inserted Successfully" << endl;
            else
               cout << "Duplicate Values Not Allowed" << endl;
            break;
         case 2:
            InOrder(root);
            break;
         case 3:
            PreOrder(root);
            break;
         case 4:
            PostOrder(root);
            break;
         case 6:
            exit(0);
         default:
            cout << "Invalid Choice" << endl;
      }
   }
   return 0;
}