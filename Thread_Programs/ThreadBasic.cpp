/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/*
    1.Function Pointer
    2.Function Object
    3.Lamda Function
*/
#include <bits/stdc++.h>
using namespace std;

// Function Pointer
void thread_function()
{
    for(int i=0; i<=10000; i++)
    {
        cout<<"This thread id:"<<this_thread::get_id()<<"\n----------Executing thread function----------\n";
    }
}

void function_pointer_thread_call()
{
    cout<<"In function pointer style of calling thread\n";
    thread th1Obj(thread_function);
    for(int i=0; i<=10000; i++)
    {
        cout<<"This thread id:"<<this_thread::get_id()<<"\nExecuting main thread function\n";
    }
    th1Obj.join();
    cout<<"Exit Of Main Thread\n";
}

//Function Object
class Function_Object
{
  public:
  void operator()()
  {
     cout<<"+++++++++Waiting for child thread to start+++++++++\n";
     for(int i=0; i<=10000; i++)
     {
        cout<<"This thread id:"<<this_thread::get_id()<<"\n----------Executing thread function----------\n";
     }
     cout<<"+++++++++Waiting for child thread to end+++++++++\n";
  }
};

void function_object()
{
    cout<<"In function object style of calling thread\n";
    cout<<"+++++++++Waiting for main thread to start+++++++++\n";
    thread threadobj((Function_Object()));
    for(int i=0; i<=10000; i++)
    {
        cout<<"This thread id:"<<this_thread::get_id()<<"\nExecuting main thread function\n";
    }
    cout<<"+++++++++Waiting for main thread to complete+++++++++\n";
    threadobj.join();
    cout<<"Exit Of Main Thread\n";
}

//Lamda Function
void lamda_function()
{
    cout<<"In lamda style of calling thread\n";
    cout<<"+++++++++Waiting for main thread to start+++++++++\n";
    thread threadobj([](){ for(int i=0; i<=10000; i++) { cout<<"This thread id:"<<this_thread::get_id()<<"\n----------Executing thread function----------\n"; } } );
    for(int i=0; i<=10000; i++) { cout<<"This thread id:"<<this_thread::get_id()<<"\nExecuting main thread function\n"; }
    cout<<"+++++++++Waiting for main thread to complete+++++++++\n";
    threadobj.join();
}

int main()
{
    int i;
    time_t start, end;
    while(1)
    {
        cout<<"Enter your choice\n";
        cout<<"1.Function Pointer 2.Function Object 3.Lamda Function 4.Exit"<<endl;
        cin>>i;
        switch(i)
        {
            case 1:
               time(&start);
               function_pointer_thread_call();
               time(&end);
               cout << "Time taken by function_pointer_thread_call is : "<< end - start << " sec " << endl;
               break;
            case 2:
              time(&start);
              function_object();
              time(&end);
              cout << "Time taken by function_object is : "<< end - start << " sec " << endl;
              break;
            case 3:
               time(&start);
               lamda_function();
               time(&end);
               cout << "Time taken by function_object is : "<< end - start << " sec " << endl;
               break;
            case 4:
               cout<<"Exiting"<<endl;
               return 0;
            deafult:
               cout<<"Wrong Choice\n";
               break;
        }
    }
    return 0;
}


