#include <iostream>
using namespace std;

class Person
{
public:
    int age;
};

class Student : public Person
{
public:
    string name;
    int rollNo;
};

class Teacher : public Person
{
public:
    string subject;
    int age;
};

int main()
{
}