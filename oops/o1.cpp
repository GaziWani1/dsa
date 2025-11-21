#include <iostream>
using namespace std;

class Teacher
{
public:
    string name;
    string dept;
    double salary;
    Teacher()
    {
        cout << "OBJECT IS CREATED" << endl;
    }
    Teacher(string name, string dept, double salary)
    {
        this->name = name;
        this->dept = dept;
        this->salary = salary;
    }

    void getInfo()
    {
        cout << this->name << " " << this->dept << " " << this->dept << " " << this->salary << endl;
    }
};

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

    Student(Student &obj)
    {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }
};

int main()
{
    // Teacher t1;
    // Teacher t1("Gazi", "CS", 908888.9998);
    // COPY CONSTRUCTOR
    // Teacher t2(t1);
    // cout << t1.dept << endl;
    // cout << t2.dept << endl;
    // t2.getInfo();
    // cout << t2.dept << endl;
    // cout << t2.name << endl;
    // cout << t2.salary << endl;

    cout << "Shallow Copy" << endl;

    Student s1("Abc", 7.9);
    Student s2(s1);
    cout << *(s1.cgpaPtr) << endl;
    cout << *(s2.cgpaPtr) << endl;

    *(s1.cgpaPtr) = 9.8;

    cout << "After Change" << endl;

    cout << *(s1.cgpaPtr) << endl;
    cout << *(s2.cgpaPtr) << endl;

    cout << "Deep Copy" << endl;

    Student s3("Abc", 7.9);
    Student s4(s3);
    cout << *(s3.cgpaPtr) << endl;
    cout << *(s4.cgpaPtr) << endl;

    *(s4.cgpaPtr) = 9.8;
    s3.name = "Amir";

    cout << "After Change" << endl;

    cout << s3.name << endl;
    cout << *(s3.cgpaPtr) << endl;
    cout << s4.name << endl;
    cout << *(s4.cgpaPtr) << endl;
}