// Online C++ compiler to run C++ program online
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
//  Linkedlist.cpp
//
//
//  Created by Jyoti Ranjan on 08/04/22.
//
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class ListNode
{
public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode * front = NULL;
void addNodeFront();
void displayLinkedList(ListNode* front);
ListNode* reverseList(ListNode* head);
ListNode* findMiddleNode();
void deleteNodeFromLinkedList();
ListNode* mergeTwoSortedListRecursive(ListNode* list1, ListNode* list2);
void createAndMergeTwoSortedLinkedList();
ListNode* mergeTwoSortedListNonRecursive(ListNode* list1, ListNode* list2);
ListNode* mergeUtil(ListNode* l1, ListNode* l2);

void addNodeFront()
{
    cout<<"Creating Liked list\n";
    int val,i=0,MAXTRY=5;
    do
    {
      if(i==MAXTRY)
      {
          string stop;
          cout<<"Do want to stop so please enter Y else N for adding\n";
          cin>>stop;
          if((!stop.compare("Y") || !stop.compare("y")))
              break;
          MAXTRY++;
          cout<<"Enter value to add node\n";
          cin>>val;
      }
      else
          val = i;
      ListNode* newnode = new ListNode(val,front);
      front = newnode;
    }while(i++<MAXTRY);
    cout<<"Created element with "<<MAXTRY<<" elements\n";
}

void displayLinkedList(ListNode* front)
{
    cout<<"Displaying Linked list\n";
    ListNode* temp = front;
    while(temp != NULL)
    {
        cout<<temp->val;
        if(temp->next)
            cout<<" -> ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* reverseList(ListNode* head)
{
    cout<<"Reversing List\n";
        ListNode* prev=NULL, *curr=head, *next=NULL;
        while(curr)
        {
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head = prev;
        return head;
}

ListNode* findMiddleNode()
{
    ListNode *sp=front, *fp=front;
    cout<<"Finding middle Node\n";
    while(sp!=NULL && fp->next!=NULL && fp->next->next!=NULL)
    {
        int i=0;
        sp=sp->next;
        fp=fp->next->next;
    }
    cout<<"Element at the middle node "<<sp->val<<endl;
    return sp;
}

void deleteNodeFromLinkedList()
{
    cout<<"Deleting the Node if present \n";
    int _val;
    cout<<"Enter the element to delete node:";
    cin>>_val;
    cout<<_val<<" will be deleted from Linkedlist\n";
    
    ListNode* delNode=front,*prev=nullptr;
    int i=0;
   
    if(front->val == _val)
    {
       front = delNode->next;
       delete delNode;
       return;
    }
    while(delNode)
    {
        if(delNode->val == _val)
           break;
        prev=delNode;
        delNode=delNode->next;
    }
    if(!delNode)
    {
        cout<<"Element Not found in Linkedlist\n";
        return;
    }
    prev->next = delNode->next;
    delete delNode;
    return;
}

ListNode* mergeUtil(ListNode* l1, ListNode* l2)
{
    if(!l1->next)
    {
        l1->next=l2;
        return l1;
    }
    ListNode *curr1=l1, *next1=l1->next;
    ListNode *curr2=l2, *next2=l2->next;
    while(next1 && curr1)
    {
        if(( curr2->val >= curr1->val ) && ( curr2->val <= next1->val ))
        {
            next2 = curr2->next;
            curr1->next = curr2;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            if(next1->next)
            {
                next1 = next1->next;
                curr1 =curr1->next;
            }
            else
            {
                next1->next = curr2;
                break;
            }
        }
    }
    return l1;
}

ListNode* mergeTwoSortedListNonRecursive(ListNode* list1, ListNode* list2)
{
    cout<<"Calling Non-recursive Method of merge\n";
    if(list1==nullptr && list2==nullptr)
    {
        return nullptr;
    }
    if(list1==nullptr)
      return list2;
    if(list2==nullptr)
      return list1;
    if(list1->val < list2->val)
    {
        return mergeUtil(list1,list2);
    }
    else
        return mergeUtil(list2,list1);
}

ListNode* mergeTwoSortedListRecursive(ListNode* list1, ListNode* list2)
{
    ListNode* temp = nullptr ;
    if(list1==nullptr && list2==nullptr )
    {
        return nullptr;
    }
    if(list1==nullptr)
      return list2;
    if(list2==nullptr)
      return list1;
    if(list1->val<=list2->val)
    {
        temp=list1;
        temp->next = mergeTwoSortedListRecursive(list1->next,list2);
    }
    else
    {
        temp=list2;
        temp->next = mergeTwoSortedListRecursive(list1,list2->next);
    }
    return temp;
}

void createAndMergeTwoSortedLinkedList()
{
    
    ListNode* f1=nullptr, *f2=nullptr;
    int val,i=0,MAXVAL=5;
    while(i++<MAXVAL)
    {
       cout<<"Enter the value to add in linklist1"<<endl;
       cin>>val;
       ListNode* newnode = new ListNode(val,f1);
       f1=newnode;
       cout<<"Enter the value to add in linklist2"<<endl;
       cin>>val;
       newnode = new ListNode(val,f2);
       f2=newnode;
    }
    f1=reverseList(f1);
    f2=reverseList(f2);
    displayLinkedList(f1);
    displayLinkedList(f2);
    ListNode* f3 = nullptr;
    if((rand()%2)==1)
    {
      cout<<"Calling Recursive Method of merge\n";
      f3 = mergeTwoSortedListRecursive(f1,f2);
       
    }
    else
       f3 = mergeTwoSortedListNonRecursive(f1,f2);
    displayLinkedList(f3);
}


int main()
{
    addNodeFront();
    displayLinkedList(front);
    front=reverseList(front);
    displayLinkedList(front);
    findMiddleNode();
    deleteNodeFromLinkedList();
    displayLinkedList(front);
    createAndMergeTwoSortedLinkedList();
    return 0;
}
