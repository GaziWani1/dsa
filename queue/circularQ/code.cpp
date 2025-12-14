#include <iostream>
using namespace std;

#define SIZE 5

class CQueue
{
    int *arr;
    int front, rear, cap, currSize;

public:
    CQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        front = 0;
        rear = -1;
    }

    void push(int x)
    {
        if (currSize == cap)
        {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % cap;
        arr[rear] = x;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front = (front + 1) % cap;
        currSize--;
    }

    int front_()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        return currSize == 0;
    }

    void display()
    {
        if (empty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main()
{
    CQueue q(5);
    q.push(10);
    q.push(34);
    q.push(2);
    q.push(5);
    q.display();
    q.pop();

    q.push(57);
    q.display();
    q.pop();
    q.display();

    return 0;
}