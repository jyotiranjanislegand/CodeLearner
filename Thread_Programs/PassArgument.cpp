//
//  PassArgument.cpp
//
//
//  Created by Jyoti Ranjan on 22/05/22.
//


#include <bits/stdc++.h>
using namespace std;
class DummyClass
{
  public:
    DummyClass(){}
    DummyClass(const DummyClass &obj){}
    void sampleMemberFunction(int x)
    {
        cout<<"Inside Sample Member Function:"<<x<<endl;
    }
};
void newThreadCallBack(int *p)
{
    cout<<"Inside Thread p:"<<p<<endl;
    chrono::milliseconds dura(1000);
    this_thread::sleep_for(dura);
    *p=19;
}

void startNewThread()
{
    int i = 10;
    cout<<"Inside Main Thread i:"<<i<<endl;
    thread t(newThreadCallBack,&i);
    cout<<"Inside Main Thread i:"<<i<<endl;
    t.detach();
}

void startNewThread2()
{
    int *p = new int();
    *p = 10;
    cout<<"Inside Main Thread p:"<<*p<<endl;
    thread t(newThreadCallBack,p);
    t.join();
    cout<<"Inside Main Thread p:"<<p<<endl;
    t.detach();
    delete p;
    p = nullptr;
}

void dummyfunc()
{
    DummyClass dummyObj;
    int x = 10;
    thread threadObj(&DummyClass::sampleMemberFunction,&dummyObj,x);
    threadObj.join();
}

int main()
{
    dummyfunc();
    //startNewThread();
   // chrono::milliseconds dura(2000);
   // this_thread::sleep_for(dura);
}

