#include <iostream>
using namespace std;

#define SIZE 5

class Stack
{
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    int isFull()
    {
        if (top == SIZE - 1)
            return 1;
        else
            return -1;
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return -1;
    }

    void push(int x)
    {
        if (isFull() == 1)
        {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        arr[++top] = x;
        cout << x << " : PUSHED" << endl;
    }

    void pop()
    {
        if (isEmpty() == 1)
        {
            cout << "STACK UNDERFLOW" << endl;
            return;
        }

        cout << arr[top--] << " POPPED" << endl;
    }

    void peek()
    {
        if (isEmpty() == 1)
        {
            cout << "STACK IS EMPTY" << endl;
            return;
        }
        cout << "TOP ELEMENT: " << arr[top] << endl;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(24);
    s.push(21);
    s.push(30);
    s.push(30);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.peek();
    return 0;
}