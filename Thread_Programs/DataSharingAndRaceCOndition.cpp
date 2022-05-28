//
//  DataSharingAndRaceCOndition.cpp
//  
//
//  Created by Jyoti Ranjan on 23/05/22.
//

#include <bits/stdc++.h>
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;

class Wallet
{
    int mMoney;
    mutex _mutex;
public:
    Wallet(int _money=0):mMoney(_money){}
    int getMoney()
    {
        return mMoney;
    }
    void addMoney(int money)
    {
        cout<<"Thread id:"<<this_thread::get_id()<<endl;
         _mutex.lock();
        for(int i=0; i<money; i++)
        {
            mMoney++;
        }
         _mutex.unlock();
    }
};

int testMultiThreadedWallet()
{
    Wallet walletObject;
    vector<thread> threads;
    for(int i=0; i<5; i++)
    {
        threads.push_back(thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for(int i=0; i<threads.size(); i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}

int main()
{
    int val=0;
    for(int k=0; k<1000; k++)
    {
        if((val = testMultiThreadedWallet()) != 5000)
           cout<<"Error Count at:"<<k<<" Money in Wallet:"<<val<<endl;
        else
           cout<<"Money in Wallet:"<<val<<endl;
    }
    return 0;
}

