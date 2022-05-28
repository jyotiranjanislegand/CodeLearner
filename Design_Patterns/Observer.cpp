/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//
//  Observer.cpp
//
//
//  Created by Jyoti Ranjan on 09/05/22.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Subscribers    //Iobserver ********
{
   public:
    virtual ~Subscribers() { cout<<"In Subscriber Destructor\n"; };
    virtual void Update(const string &notification_from_youtube) = 0;
};

class Youtube  //Isubject
{
   public:
    virtual ~Youtube(){ cout<<"In Youtube Destructor\n"; }
    virtual void Attach(Subscribers *Observ) = 0;
    virtual void Detach(Subscribers *Observ) = 0;
    virtual void notify() = 0;
};

class Channel : public Youtube
{
   private:
    string _name;
    string _message;
    list<Subscribers*> list_Subscriber;
    
   public:
    Channel(string name)
    {
        this->_name = name;
    }
    
    virtual ~Channel()
    {
        cout<<"Deleting the channel\n";
        cout<<"In Channel Subsriber\n";
    }
    
    void Attach(Subscribers *Observ) override
    {
        list_Subscriber.push_back(Observ);
    }
    
    void Detach(Subscribers *Observ)
    {
        list_Subscriber.remove(Observ);
    }
    
    void notify()
    {
        cout<<"There are "<<list_Subscriber.size()<<" Subscribers in the Channel"<<endl;
        for(list<Subscribers*>::iterator it = list_Subscriber.begin(); it != list_Subscriber.end(); it++)
        {
            (*it)->Update(_message);
        }
    }
    
    void createVideo(string message = "")
    {
        this->_message = "Video Uploaded to Channel " + message;
        notify();
    }
    
    void uploadVideo()
    {
        this->_message = "Video Uploaded to Channel"+ _name;
        notify();
        cout<<"Video Uploaded\n";
    }
};

class Subscriber : public Subscribers
{
   private:
    string messageFromYoutube;
    Youtube &youtube;
    static int _static_number;
    int _number;
    string name;
public:
    Subscriber(Youtube &_youtube,string _name):youtube(_youtube),name(_name)
    {
        this->youtube.Attach(this);
        cout<<"Subscribers Increased: "<<++Subscriber::_static_number<<"\n";
        this->_number = Subscriber::_static_number;
    }
    ~Subscriber()
    {
        cout<<"In Subscriber Destructor\n"<<this->_number<<endl;;
    }
    void Update(const string &notification_from_youtube) override
    {
        messageFromYoutube = notification_from_youtube;
        cout<<"Hey Subscriber "<<this->_number<<"\n"<<" New Video available is "<<messageFromYoutube<<endl;
    }
    void RemoveFromList()
    {
        youtube.Detach(this);
        cout<<" Subscriber "<<_number<<"\n"<<this->name<<" removed from List.\n";
    }
};

int Subscriber::_static_number = 0;

void clientCode()
{
    Channel* ytb = new Channel("Travelling Monk");
    Subscriber *_subscriber1 = new Subscriber(*ytb,"A1");
    Subscriber *_subscriber2 = new Subscriber(*ytb,"A2");
    Subscriber *_subscriber3 = new Subscriber(*ytb,"A3");
    Subscriber *_subscriber4;
    Subscriber *_subscriber5;
    
    ytb->createVideo("Kerla trip");
    _subscriber3->RemoveFromList();
    ytb->createVideo("Odisha trip");
    _subscriber4 = new Subscriber(*ytb,"A4");
    
    _subscriber2->RemoveFromList();
    _subscriber5 = new Subscriber(*ytb,"A5");
    
    ytb->createVideo("Munnar trip");
    _subscriber5->RemoveFromList();
    _subscriber4->RemoveFromList();
    _subscriber1->RemoveFromList();
    
    delete _subscriber1;
    delete _subscriber2;
    delete _subscriber3;
    delete _subscriber4;
    delete _subscriber5;
    delete ytb;
}

int main()
{
    clientCode();
}

