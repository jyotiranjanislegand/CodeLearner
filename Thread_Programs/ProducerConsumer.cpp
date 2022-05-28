/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
//  ProducerConsumer.cpp
//
//
//  Created by Jyoti Ranjan on 26/05/22.
//

#include <bits/stdc++.h>
using namespace std;
mutex _mutex_1,_mutex_2;
condition_variable cv;

class Buffer
{
    deque<int> _buffer;
    const unsigned int max_size = 10;
public:
    Buffer(){}
    void add(int ele)
    {
        while(1)
        {
            unique_lock<mutex> locker(_mutex_1);
            cv.wait(locker,[this](){ return _buffer.size() < max_size; });
            _buffer.push_back(ele);
            locker.unlock();
            cv.notify_all();
            return;
        }
    }
    int remove()
    {
        while(1)
        {
            unique_lock<mutex> locker(_mutex_1);
            cv.wait(locker,[this](){ return _buffer.size() > 0; });
            int back = _buffer.back();
            _buffer.pop_back();
            locker.unlock();
            cv.notify_all();
            return back;
        }
    }
};
class Producer
{
    Buffer* _buffer;
public:
    Producer(Buffer* _buf)
    {
        this->_buffer = _buf;
    }
    void run()
    {
        while(1)
        {
            int num = rand()%100;
            _buffer->add(num);
            _mutex_2.lock();
            cout<<"Produced:"<<num<<endl;
            this_thread::sleep_for(std::chrono::milliseconds(50));
            _mutex_2.unlock();
        }
    }
};
class Consumer
{
    Buffer* _buffer;
public:
    Consumer(Buffer* _buf)
    {
        this->_buffer = _buf;
    }
    void run()
    {
        while(1)
        {
            int num = _buffer->remove();
            _mutex_2.lock();
            cout<<"Consumed:"<<num<<endl;
            this_thread::sleep_for(chrono::milliseconds(50));
            _mutex_2.unlock();
        }
    }
};

void client()
{
    Buffer b;
    Producer p(&b);
    Consumer c(&b);
    thread producer_thread(&Producer::run, &p);
    thread consumer_thread(&Consumer::run, &c);
    producer_thread.join();
    consumer_thread.join();
}

int main()
{
    client();

    return 0;
}
