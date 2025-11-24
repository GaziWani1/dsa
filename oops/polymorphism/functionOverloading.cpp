#include <iostream>
using namespace std;

class A
{
public:
    void fun(int a)
    {
        cout << a << endl;
    }

    void fun(string a)
    {
        cout << a << endl;
    }
};

int main()
{

    A a;
    // a.fun(3);
    a.fun("Gazi");
    return 0;
}