
// Array Data Structure for integer input only.

#include <iostream>
#include <stdlib.h>

struct Array
{
   int capacity;
   int lastIndex;
   int *ptr;
};

//function declaration

Array* CreateArray(int);
void Append(Array*,int);
void Insert(Array*,int,int);
void Delete(Array*,int);
void ViewElements(Array*);
void HalfArray(Array*);
void DoubleArray(Array*);


//fuction definition

Array* CreateArray(int cap)
{
   Array* arr;
   arr=(Array*)malloc(sizeof(Array));
   arr->ptr=(int*)malloc(sizeof(int)*cap);
   arr->capacity=cap;
   arr->lastIndex=-1;
   return arr;
}


void Append(Array* arr,int data)
{
   if(arr->lastIndex+1==arr->capacity)
      std::cout<<"Overflow"<< std::endl;
   else
   {
      arr->ptr[arr->lastIndex+1]=data;
      arr->lastIndex+=1;
   }
}


void ViewElements(Array* arr)
{
   int i;
   for(i=0;i<arr->lastIndex;i++)
      std::cout<<arr->ptr[i]<<" ";
}


void Insert(Array* arr,int index,int data)
{
   if(arr->lastIndex==arr->capacity)
      std::cout<<"Overflow"<<std::endl;
   else if(index<0)
      std::cout<<"Invalid Index"<<std::endl;
   else
   {
      int i;
      for(i=0;i<index;i++)
      {
         arr->ptr[arr->lastIndex+i]=arr->ptr[arr->lastIndex];
      }
      arr->ptr[index]=data;
      arr->lastIndex+=1;
   }
}


void Delete(Array*arr,int index)
{
   
}


int main()
{
   int capacity;
   Array *arr;
   arr=CreateArray(capacity);
   return 0;
}