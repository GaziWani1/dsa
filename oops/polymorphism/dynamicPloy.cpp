#include <iostream>
using namespace std;

class Parent
{
public:
    void getInfo()
    {
        cout << "parent class\n";
    }
    virtual void hello()
    {
        cout << "hello parent\n";
    }
};

class Child : public Parent
{
public:
    void getInfo()
    {
        cout << "child class\n";
    }
    // void hello()
    // {
    //     cout << "hello child\n";
    // }
};

int main()
{
    Child c;
    c.getInfo();
    c.hello();
}