//
//  ThreadPassArgument.cpp
//  
//
//  Created by Jyoti Ranjan on 22/05/22.
//

#include<bits/stdc++.h>
using namespace std;

void threadCallBack(int x, string str)
{
    cout<<"Number :"<<x<<endl;
    cout<<"String Val:"<<str<<endl;
}

void callThread()
{
    int x=10;
    string str = "Sample String";
    thread threadObj(threadCallBack, x, str);
    threadObj.join();
}

int main()
{
    callThread();
    return 0;
}
