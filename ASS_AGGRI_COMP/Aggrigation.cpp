//
//  Aggrigation.cpp
/*  Aggregation is a specialize form of Association where all object have their own lifecycle but there is a ownership like parent and child. Child object can not belong to another parent object at the same time. We can think of it as "has-a" relationship.
    Created by Jyoti Ranjan on 06/04/22.
*/

//
//  Aggrigation.cpp
/*  Aggregation is a specialize form of Association where all object have their own lifecycle but there is a ownership like parent and child. Child object can not belong to another parent object at the same time. We can think of it as "has-a" relationship.
    Created by Jyoti Ranjan on 06/04/22.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Company;
class Employee
{
    int m_Empid;
    string m_EmployeeName;
    string m_BloodGroup;
    string m_Company;
    bool assigned;
public:
    Employee(int _employeeId = 0, string _employeeName = "", string _bloodGroup="")
    {
        m_Empid = _employeeId;
        m_EmployeeName = _employeeName;
        m_BloodGroup = _bloodGroup;
        m_Company = "";
        assigned = false;
    }
    ~Employee()
    {
        m_Company = "";
        assigned = false;
    }
    void display() const
    {
        cout<<"EmployeeName: "<<m_EmployeeName<<" EmployeeId: "<<m_Empid<<" Blood Group: "<<m_BloodGroup<<endl;
    }
    void setAssigned(bool assign) { assigned = assign; }
    bool checkIfAssigned() const { return assigned; }
    int getEmpId() const { return m_Empid; }
    string getEmployeeName() const { return m_EmployeeName; }
    string getEmployeeBloodGroup() const { return m_BloodGroup; }
    void setCompnay(string _company) { m_Company = _company;}
    string getCompany() const { return m_Company;}
};
class Company
{
    Employee* m_Employee;
    string m_CompanyName;
    vector<Employee*> m_EmployeeList;
public:
    Company(string _companyName)
    {
        m_CompanyName = _companyName;
    }
    void addEmployee(Employee* _employee)
    {
        if(!_employee->checkIfAssigned())
        {
            m_Employee = _employee;
            m_Employee->setAssigned(true);
            m_EmployeeList.push_back(m_Employee);
            m_Employee->setCompnay(m_CompanyName);
        }
        else
        {
            cout<<"Employee "<<_employee->getEmployeeName()<<"is already part of : "<<_employee->getCompany()<<endl;
        }
    }
    void display() const
    {
        cout<<m_CompanyName<<endl;
        
        for(int i=0; i<m_EmployeeList.size(); i++)
            m_EmployeeList[i]->display();
        cout<<endl;
    }
    ~Company()
    {
        m_CompanyName = "";
        m_Employee = NULL;
        m_EmployeeList.clear();
    }
};
int main()
{
    Employee emp(331,"Ramesh", "A+ve");
    Employee emp1(332,"Rajesh", "B+ve");
    Company p1 = Company("Reltel Communication");
    p1.addEmployee(&emp);
    p1.addEmployee(&emp1);
    p1.display();
    Company p2 = Company("Bigbazzar");
    p2.addEmployee(&emp);
    p2.display();
}
