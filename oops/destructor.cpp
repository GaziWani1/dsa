#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    double *cgpaPtr;
    // Shallow Copy
    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa; // derefrence
    }

    ~Student()
    {
        cout << "I DELETE EVERYTHING" << endl;
    }
};

int main()
{

    Student s1("Abc", 7.9);
    Student s2(s1);
    cout << *(s1.cgpaPtr) << endl;
    cout << *(s2.cgpaPtr) << endl;
    return;
}