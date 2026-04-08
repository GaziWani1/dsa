#include <iostream>
using namespace std;
const int SIZE = 10;
class Queue
{
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1, rear = -1;
    }

    void nQueue(int val)
    {
        if (rear == SIZE - 1)
        {
            cout << "QUEUE IS FULL " << endl;
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = val;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Undjerflow\n";
            return;
        }

        // cout << arr[front] << " removed\n" << end;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {

            cout << front << endl;
            front = (front + 1) % SIZE;
            cout << front << endl;
            cout << "-------------------------------------" << endl;
        }
    }

    void print()
    {
        if (front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Circular Queue: ";

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % 5;
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
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}