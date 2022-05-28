/*Background
 Association is a simple structural connection or channel between classes and is a relationship where all objects have their own lifecycle and there is no owner.
 Lets take an example of Department and Student.
 Multiple students can associate with a single Department and single student can associate with multiple Departments, but there is no ownership between the objects and both have their own lifecycle. Both can create and delete independently.
 Here is respective Model and Code for the above example.*/
#include <iostream>
#include <string>
using namespace std;
class Department;
class Student
{
    string sName;
public:
    Student(string _name="") { sName = _name; }
    ~Student(){ cout<<"Student Destructure\n" ;}
    string getStudentName() const { return sName; }
};
class Department
{
    string deptName;
public:
    Department(string _deptName="") { deptName =_deptName; }
    ~Department(){ cout<<"Department Destructure\n" ; }
    string getDepartmentName() const { return deptName;}
};
class Course
{
    string courseName;
    Student *std;
    Department *dept;
    static int index;
    static Course* courseList[4];
public:
    Course(string _courseName="", Student* _std=NULL, Department* _dept=NULL)
    {
        if(index<4)
        {
            courseName = _courseName;
            std = _std;
            dept = _dept;
            courseList[index++] = this;
        }
        else
        {
            cout<<"Student limit crossed"<<endl;
        }
    }
    ~Course()
    {
        cout<<"In Course destructor"<<endl;
        std=NULL;
        dept=NULL;
    }
    static string getStudentName(string dept, string cseName)
    {
        for(int i=0;i<4;i++)
        {
            if(courseList[i]->getDepartmentName() == dept && courseList[i]->getCourseName()==cseName)
            {
                cout<<"-----------"<<i<<endl;
                return courseList[i]->getStudentName();
            }
        }
        return "";
    }
    string getStudentName() const { return std->getStudentName(); }
    string getDepartmentName() const { return dept->getDepartmentName(); }
    string getCourseName() const { return courseName;}
};
int Course::index = 0;
Course* Course::courseList[4]={0,0,0,0};
int assiociation_fun()
{
    cout<<"Example of Assiociation Function\n";
    cout<<"------------------------------"<<endl;
            
    cout<<"We have 4 Students\n";
    cout<<"---------------------------------------------"<<endl;

    Student *studentNames[4] = {new Student("----XX1----"),new Student("----XX2----"),new Student("----XX3----"),new Student("----XX4----")};
    cout<<"\n";
    cout<<"We have 2 Department\n";
    cout<<"---------------------------------------------"<<endl;

    Department *department[2] = {new Department("Mathemetics"),new Department("ComputerSceince")};
    cout<<"\n";
    cout<<"Here are the courses assiociated with the department and student"<<endl;
    Course cs1("Datastructure",studentNames[0],department[1]);
    Course cs2("Math1",studentNames[1],department[0]);
    Course cs3("Geometry",studentNames[2],department[0]);
    Course cs4("Compiler Design",studentNames[3],department[1]);
    cout<<"\n";
    cout<<"Finding the student having department"<<endl;
    cout<<"Student who has taken Math1 Course in Mathemetics Department is:"<<Course::getStudentName("Mathemetics","Math1")<<endl;
    cout<<"Student who has taken Geometry Course in Mathemetics Department is:"<<Course::getStudentName("Mathemetics","Geometry")<<endl;
    cout<<"Student who has taken Datastructure Course in ComputerSceince Department is:"<<Course::getStudentName("ComputerSceince","Datastructure")<<endl;
    cout<<"Student who has taken Compiler Design Course in ComputerSceince Department is:"<<Course::getStudentName("ComputerSceince","Compiler Design")<<endl;
    cout<<"\n";
    for(int i=0;i<2;i++)
    {
        delete department[i];
    }
    cout<<"\n";
    return 0;
}
int main()
{
    return assiociation_fun();
}
