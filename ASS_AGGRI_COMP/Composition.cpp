//
//  Composition.cpp
/*  Composition is again specialize form of Aggregation. It is a strong type of Aggregation.
    Here the Parent and Child objects have coincident lifetimes.
    Child object dose not have it's own lifecycle and if parent object gets deleted, then all of it's child objects will also be deleted.
 Implentation details:

  -   Typically we use normal member variables
  -   Can use pointer values if the composition class automatically handles
 allocation/deallocation
  -  Responsible for creation/destruction of subclasses
 */
//
//  Created by Jyoti Ranjan on 06/04/22.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;
class House;
class Room
{
    string m_roomName;
    House *m_Hse;
public:
    Room()
    {
        cout<<"Default Constructor Of Room\n";
    }
    Room(House *_hse, string _name)
    {
        cout<<"Parameterized Constructor Of Room\n";
        m_Hse = _hse;
        if(m_Hse != NULL)
        {
            m_roomName = _name;
        }
        else
        {
            cout<<"House Itself is not created\n"<<endl;
        }
    }
    ~Room()
    {
        cout<<"Room Destructor is ";
        m_Hse=NULL;
        m_roomName.clear();
    }
    static void createRoom(Room* (&_room), House *_hse, string _name)
    {
        _room = new Room(_hse,_name);
    }
    static void createRoomList(Room* (& roomList)[3])
    {
        roomList[3] = new Room[3];
    }
    void display() const
    {
        cout<<m_roomName<<endl;
    }
};
class House
{
    string m_houseName;
    Room* m_RoomList[3];
public:
    House(string _name)
    {
        cout<<"Constructor Of house"<<endl;
        m_houseName = _name;
        Room::createRoomList(m_RoomList);
        
        Room* myRoom;
        Room::createRoom(myRoom, this, "Kitchen");
        m_RoomList[0] = myRoom;
        
        Room::createRoom(myRoom, this, "BedRoom");
        m_RoomList[1] = myRoom;
        
        Room::createRoom(myRoom, this, "Drawing Room");
        m_RoomList[2] = myRoom;
    }
    ~House()
    {
        cout<<"Destructor Of house"<<endl;
        cout<<"Deleting all rooms"<<endl;
        for(int i=0; i<3; i++)
        {
            if(m_RoomList[i] != NULL)
            {
                cout<<"Destorying ";
                m_RoomList[i]->display();
                cout<<endl;
                delete m_RoomList[i];
            }
        }
        delete [] m_RoomList;
        m_houseName.clear();
    }
    void display()
    {
        cout<<"House Name is :"<<m_houseName<<endl;
        if(m_RoomList != NULL)
        {
            unsigned int i ;
            cout<<"Room Details"<<endl;
            for(i=0; i<3; i++)
            {
                if(NULL != m_RoomList[i])
                {
                    m_RoomList[i]->display();
                }
            }
            cout<<endl;
        }
    }
};
int main()
{
    cout<<"\nExample of Composition Relationship\n";
    cout<<"-----------------------------------------\n\n";
    House hse("Vishranti Nilaya");
    cout<<"\n\nHouse details...\n";
    hse.display();
    cout<<"Here House itself creates the Rooms and Deletes as well, before it gets deletd...\n";
    return(0);
}
