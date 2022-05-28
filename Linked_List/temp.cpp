class MyLinkedList {
public:
    ListNode *head,*tail;
    int size=0;
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    
    void print()
    {
        if(!head)
            return;
        ListNode *cur1 = head;
        while(cur1 != nullptr)
        {
            cout<<cur1->val<<"->";
            cur1 =cur1->next;
        }
        cout<<"nullptr\n";
    }
    
    int get(int index)
    {
       if(index>=size) return -1;
       cout<<"get value of index: "<<index<<endl;
       vector<int> vecList;
       for(ListNode* temp = head ;temp!=nullptr; temp=temp->next)
           vecList.push_back(temp->val);
       for(auto s:vecList)
           cout<<s<<" ";
       cout<<endl;
       if(index<vecList.size())
           return vecList[index];
       else
           return -1;
    }
    
    void addAtHead(int val)
    {
        cout<<"Addind at the head "<<val<<endl;
        ListNode* newnode = new ListNode(val);
        if(!head)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        size++;
        print();
    }
    
    void addAtTail(int val)
    {
        cout<<"Addind at the tail "<<val<<endl;
        ListNode* newnode = new ListNode(val);
        if(!tail)
        {
            tail = head = newnode;
        }
        else
        {
            tail->next = newnode;
        }
        size++;
        print();
    }
    
    void addAtIndex(int index, int val)
    {
        if(index > size)
            return;
        cout<<"Addind at the index: "<<index<<" with val: "<<val<<endl;
        ListNode *curr = head, *prev = head;
        for(int i=0;i<index;i++)
        {
            if(!curr)
                break;
            prev = curr;
            curr = curr->next;
        }
        ListNode* newnode = new ListNode(val);
        if(head == curr)
        {
            newnode->next = head->next;
            head = newnode;
        }
        else
        {
            if(prev && prev->next)
            {
                newnode->next = prev->next;
                prev->next = newnode;
            }
            if(prev && !prev->next)
            {
                prev->next = newnode;
                tail = prev->next;
            }
        }
        size++;
        print();
        return ;
    }
    
    void deleteAtIndex(int index)
    {
        if(index>=size) return;
        cout<<"Deleting at the index: "<<index<<endl;
        print();
        ListNode *curr = head;
        if(index == 0)
        {
            head = head->next;
            return;
        }
        for(int i=1;i<index;i++)
        {
            if(!curr)
                break;
            curr = curr->next;
        }
        if(curr && curr->next)
        {
            curr->next = curr->next->next;
        }
        if(curr && !curr->next)
            tail = curr;
        size--;
        print();
        return ;
    }
};

