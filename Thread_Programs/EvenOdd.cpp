//
//  EvenOdd.cpp
//
//
//  Created by Jyoti Ranjan on 24/05/22.
//

#include <bits/stdc++.h>
using namespace std;

class printEvenOdd
{
    int val,max;
    mutex _mutex;
    condition_variable cv;
public:
    printEvenOdd(int _val=0, int _max=100):val(_val),max(_max){}
    void printEven()
    {
        while(val<=max)
        {
            unique_lock<mutex> mlock(_mutex);
            cv.wait(mlock,[&](){ return (val%2 == 0) ;} );
            cout<<"Printing Even val:"<<val++<<endl;
            cv.notify_all();
        }
    }
    
    void printOdd()
    {
        while(val<=max)
        {
          unique_lock<mutex> mlock(_mutex);
          cv.wait(mlock,[&](){ return (val%2 != 0) ;} );
          cout<<"Printing Odd Val:"<<val++<<endl;
          cv.notify_all();
        }
    }
};

int main()
{
    printEvenOdd obj;
    thread th1(&printEvenOdd::printEven,&obj);
    thread th2(&printEvenOdd::printOdd,&obj);
    th1.join();
    th2.join();
    return 0;
}
