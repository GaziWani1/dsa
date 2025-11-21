#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
public:
    int rollNo;

    Student(string name, int age, int rollno) : Person(name, age)
    {
        this->rollNo = rollno;
    }

    void getInfo()
    {
        cout << age << endl;
        cout << name << endl;
        cout << rollNo << endl;
    }
};

int main()
{
    Student s1("Gazi", 24, 122);
    s1.getInfo();
    return 0;
}