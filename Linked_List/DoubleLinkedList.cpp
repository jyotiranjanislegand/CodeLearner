/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//  DoubleLinkedList.cpp
//  Created by Jyoti Ranjan on 08/04/22.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class DListNode
{
public:
     int val;
     DListNode *next,*prev;
     DListNode() : val(0), next(nullptr), prev(nullptr) {}
     DListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
     DListNode(int x, DListNode *next, DListNode *prev) : val(x), next(next), prev(prev) {}
};
DListNode * front = NULL;
void addNodeFront()
{
    cout<<"Creating linkedlist By adding Node\n";
    int val,i=0,MaxEle=5;
    do
    {
      if(i==MaxEle)
      {
         cout<<"Do want to stop as max element already entered. so please enter Y. Enter N for adding more\n";
         string stop;
         cin>>stop;
         if((!stop.compare("Y") || !stop.compare("y")))
           break;
         cout<<"Enter value to add node\n";
         cin>>val;
         MaxEle++;
      }
      else
         val=i;
      DListNode* newnode = new DListNode(val,nullptr,nullptr);
      if(!front)
      {
         front = newnode;
         continue;
      }
      newnode->next = front;
      newnode->next->prev = newnode;
      front=newnode;
    }while(i++ < MaxEle);
    cout<<"Added "<<MaxEle<<" To the Linkedlist"<<endl;
}

void displayLinkedList()
{
    cout<<"Displaying the Linkedlist"<<endl;
    DListNode* temp = front;
    while(temp != NULL)
    {
        cout<<temp->val;
        if(temp->next)
            cout<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}

void diplsyLinkedListFromEnd()
{
    cout<<"Displaying the Linkedlist From End"<<endl;
    DListNode* temp = front;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != front)
    {
        cout<<temp->val;
           cout<<" -> ";
        temp=temp->prev;
    }
    cout<<temp->val;
    cout<<endl;
}

void reverseDoubleLinkedList()
{
    cout<<"Reversing The Linkedlist\n";
    if(front==nullptr)
    {
       cout<<"Empty Linkedlist\n";
       return;
    }
    DListNode* prev=nullptr, *curr=front; /*next=curr->next;*/
    while(curr)
    {
        
        /*
         curr->prev=next;
         curr->next=prev;
         prev=curr;
         curr=next;
         if(curr)
           next=curr->next;*/
        curr->prev = curr->next;
        curr->next = prev;
        prev=curr;
        curr=curr->prev;
    }
    front=prev;
}

void deleteNodeFromLinkedList()
{
    cout<<"Deleting the Node if present \n";
    int _val;
    cout<<"Enter the element to delete node:";
    cin>>_val;
    cout<<_val<<" will be deleted from Linkedlist\n";
    
    DListNode* delNode=front;
    int i=0;
   
    if(front->val == _val)
    {
       front = delNode->next;
       delNode->next->prev=nullptr;
       delete delNode;
       return;
    }
    while(delNode)
    {
        if(delNode->val == _val)
           break;
        delNode=delNode->next;
    }
    if(!delNode)
    {
        cout<<"Element Not found in Linkedlist\n";
        return;
    }
    delNode->prev->next = delNode->next;
    if(delNode->next != nullptr)
       delNode->next->prev = delNode->prev;
    delete delNode;
    return;
}


int main()
{
    addNodeFront();
    displayLinkedList();
    diplsyLinkedListFromEnd();
    displayLinkedList();
    reverseDoubleLinkedList();
    displayLinkedList();
    deleteNodeFromLinkedList();
    displayLinkedList();
    return 0;
}

