/*OwnSmartPointerHCR.cpp 
  Shared Own Smart Pointer
1.Construction
2.Copy
3.Assignment
4.SpecialCase*/

#include <iostream>
#include <string>

class Car{};

class Test {
public:
    enum TestType{NoTest, ConstDest, Copy, Assignment, SpecialCase};
    Test(const TestType& t_) : _t(t_)  {}

    int constDestTest() const;
    int copyTest() const;
    int assignmentTest() const;
    int specialCaseTest() const;

    void run() const;
private:
    TestType _t;
    const std::string _help = "Type ONLY ONE from the following values to STDIN to run tests: Construction, Copy, Assignment, SpecialCase";
};

Test::TestType getTestType()
{
    std::string type;
    std::getline(std::cin, type);
    if ( type == "Construction" )
        return Test::TestType::ConstDest;
    if ( type == "Copy" )
        return Test::TestType::Copy;
    if ( type == "Assignment" )
        return Test::TestType::Assignment;
    if ( type == "SpecialCase" )
        return Test::TestType::SpecialCase;

    return Test::TestType::NoTest;
}

class RC
{
private:
    int count;
public:
    RC()
    {
       count=0;
    }
    RC(int c):count(c)
    {

    }
    void addCount()
    {
        count++;
    }
    int getCount()
    {
       return count--;
    }
    int getC()
    {
        return count;
    }
};
template<typename T>
class shared_ptr{
private:
    T*  pData;
    RC* reference;
public:
    shared_ptr():pData(0),reference(0)
    {
        reference=new RC;
        reference->addCount();
    }
    shared_ptr(T* ptr):pData(ptr),reference(0)
    {
        reference=new RC;
        reference->addCount();
    }
    ~shared_ptr()
    {
        if(reference->getCount()==0)
        {
            delete pData;
            delete reference;
        }
    }
    T& operator *()
    {
        return  *pData;
    }
    T* operator->()
    {
        return pData;
    }
    shared_ptr(const shared_ptr<T>& other):pData(other.pData),reference(other.reference)
    {
        reference->addCount();
    }
    shared_ptr& operator=(const shared_ptr<T>& other)
    {
        if(this!=&other)
        {
            if(reference->getCount()==0)
            {
                delete pData;
                delete reference;
            }
            pData=other.pData;
            reference=other.reference;
            reference->addCount();
        }
        return *this;
    }

    int getCount()
    {
        std::cout<<this->reference->getC()<<std::endl;
        return this->reference->getC();
    }
};
int main() {
    Test test(getTestType());
    shared_ptr<int> ptr(new int);

    test.run();

    return 0;
}

int Test::constDestTest() const
{
    shared_ptr<int> p1(new int);
    shared_ptr<int> p2(new int);
    shared_ptr<int> p3(new int);
    return p1.getCount() + p2.getCount() + p3.getCount();
}

int Test::copyTest() const
{
    shared_ptr<std::string> p1(new std::string);
    shared_ptr<std::string> p2(new std::string);
    shared_ptr<std::string> p3(new std::string);
    shared_ptr<std::string> p4(p1);
    shared_ptr<std::string> p5(p2);
    {
        shared_ptr<std::string> pTemp(p3); //tests also destructor
    }
    return p1.getCount() + p2.getCount() + p3.getCount() + p4.getCount() + p5.getCount();
}

int Test::assignmentTest() const
{
    shared_ptr<Car> p1(new Car);
    shared_ptr<Car> p2(new Car);
    shared_ptr<Car> p3(new Car);
    shared_ptr<Car> p4(new Car);
    shared_ptr<Car> p5(new Car);
    p4 = p1;
    p5 = p1;
    p3 = p4;
    return p1.getCount() + p2.getCount() + p3.getCount() + p4.getCount() + p5.getCount();
}

int Test::specialCaseTest() const
{
    shared_ptr<Car> p1(new Car);
    shared_ptr<Car> p2(new Car);
    shared_ptr<Car> p3(new Car);
    p1 = p1;
    p2 = p1;
    p2 = p2;
    p3 = p3;
    return p1.getCount() + p2.getCount() + p3.getCount();
}

void Test::run() const
{

    switch (_t)
    {
        case TestType::ConstDest:
            std::cout << constDestTest();
            //break;
        case TestType::Copy:
            std::cout << copyTest();
           // break;
        case TestType::Assignment:
            std::cout << assignmentTest();
            //break;
        case TestType::SpecialCase:
            std::cout << specialCaseTest();
            //break;
        default:
            std::cout << _help;
            break;
    }
}
