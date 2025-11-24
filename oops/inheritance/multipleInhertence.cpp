#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;
};
class Teacher
{
public:
    string subject;
    int age;
};
class TA : public Student, public Teacher
{
};

int main()
{
}