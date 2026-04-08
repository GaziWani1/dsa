#include <iostream>
using namespace std;
const int size = 100;
class Queue
{
    int arr[size];
    int front, rear;

public:
    Queue()
    {
        front = -1, rear = -1;
    }

    void nQueue(int val)
    {
        if (rear == size - 1)
        {
            cout << "QUEUE IS FULL " << endl;
            return;
        }
        if (front == -1)
            front++;
        arr[++rear] = val;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "QUEUE IS EMPTY " << endl;
            return;
        }
        front++;
    }

    void print()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.nQueue(1);
    q.nQueue(13);
    q.nQueue(12);
    q.nQueue(11);
    q.nQueue(119);
    q.print();

    return 0;
}