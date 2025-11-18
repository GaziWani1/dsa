#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *ptr = &a;
    int **ptrPtr = &ptr;
    cout << a << endl;
    cout << *(&a) << endl;
    cout << ptr << endl;
    cout << ptrPtr << endl;
    cout << **(ptrPtr) << endl;
}