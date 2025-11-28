#include <iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int *ptr = &a;
    // int **ptrPtr = &ptr;
    // cout << a << endl;
    // cout << *(&a) << endl;
    // cout << ptr << endl;
    // cout << ptrPtr << endl;
    // cout << **(ptrPtr) << endl;

    int a = 5;
    int *p = &a;
    int **q = &p;

    cout << a << endl;
    cout << **q << endl;
    cout << p << endl;
    cout << *q << endl;
}