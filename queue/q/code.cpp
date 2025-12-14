#include <iostream>
using namespace std;

#define SIZE 5

class Queue
{
    int arr[SIZE];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return rear == SIZE - 1;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << arr[front] << " : REMOVED" << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(34);
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(57);

    q.display();

    q.dequeue();
    cout << "After Enqueue\n";
    q.display();
    return 0;
}