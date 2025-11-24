#include <iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;
};

class Student : public Person
{
    int rollNo;
};
class GradStudent : public Student
{
    string researchArea;
};

int main()
{
}