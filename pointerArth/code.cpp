#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int v = 90;
    int *p = &a;
    int *q = &v;
    int *o = &v;
    // cout << p << endl;
    // p++;
    // cout << p << endl;
    // cout << p + 90 << endl;
    cout << p - q << endl;
    cout << (q == o) << endl;

    // int arr[] = {1, 2, 3, 4, 5, 6};

    // cout << *arr << endl;
    // cout << *arr + 1 << endl;
    // cout << *arr + 3 << endl;
}