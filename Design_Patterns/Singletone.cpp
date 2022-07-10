/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
//  Singletone.cpp
//
//
//  Created by Jyoti Ranjan on 11/07/22.
//

#include <bits/stdc++.h>
using namespace std;
class Singletone
{
private:
    static Singletone* s_instance;
    static mutex _mutex;
    string value_;
    Singletone(string s=""):value_(s)
    {}
    ~Singletone(){}
public:
    Singletone(const Singletone& other)=delete;
    void operator=(const Singletone& )=delete;
    static Singletone* GetInstance(string value)
    {
        lock_guard<mutex> lock(_mutex);
        if(!s_instance)
        {
            s_instance = new Singletone(value);
        }
        return s_instance;
    }
    string value() const{
        return value_;
    }
};
Singletone* Singletone::s_instance=nullptr;
mutex Singletone::_mutex;

void t1()
{
    while(1)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        Singletone* singletone = Singletone::GetInstance("Foo");
        cout<<singletone->value()<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

void t2()
{
    while(1)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        Singletone* singletone = Singletone::GetInstance("Bar");
        cout<<singletone->value()<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}
int main()
{
    cout<<"If We see same value then singletone was reused\n";
    cout<<"If you see different values, then 2 singletons were created (booo!!)\n\n" <<endl;
    std::thread _t1(t1);
    std::thread _t2(t2);
    _t1.join();
    _t2.join();
    return 0;
}
