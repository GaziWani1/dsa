#include <iostream>
using namespace std;

void change(int *b) // pass by pointers
{
    *b = 90;
}

void change2(int &b) // pass by alais
{
    b = 99;
}

int main()
{
    int a = 30;
    change(&a);
    cout << a << endl;
    change2(a);
    cout << a;
}