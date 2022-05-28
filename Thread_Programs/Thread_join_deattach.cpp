//
//  Thread_join_deattach.cpp
//  
//
//  Created by Jyoti Ranjan on 22/05/22.
//

#include<bits/stdc++.h>
using namespace std;
class ThreadRAII
{
    thread & m_thread;
public:
    ThreadRAII(thread &threadOBJ): m_thread(threadOBJ)
    {
        m_thread.join();
    }
    ~ThreadRAII()
    {
        if(m_thread.joinable())
        {
            m_thread.detach();
        }
    }
};

void threadFunction()
{
    for(int i=0; i<10000; i++)
    {
        cout<<"Thread function Executing"<<endl;
    }
}

void threadDetach()
{
    thread threadOBJ(threadFunction);
    ThreadRAII obj(threadOBJ);
}

int main()
{
    threadDetach();
    return 0;
}
