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

class GradStudent : public Student
{
};

class TA : public Teacher, public Student
{
};
int main()
{
}