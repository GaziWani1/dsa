#include <iostream>
using namespace std;
const int size = 100;
class Stack
{
    int arr[size];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "STACK IS FULL " << endl;
            return;
        }
        arr[++top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "STACK IS EMPTY " << endl;
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "STACK IS EMPTY " << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack elements (top to bottom):\n";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(13);
    s.push(12);
    s.push(11);
    s.push(119);
    s.print();

    return 0;
}