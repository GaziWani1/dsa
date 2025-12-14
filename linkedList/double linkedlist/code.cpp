#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }
        Node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void popBack()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (head != NULL)
        {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.push_front(90);
    dll.push_front(9);
    dll.push_front(28);
    dll.push_front(19);
    dll.push_front(7);

    dll.push_back(89);
    dll.push_back(1);

    dll.print();

    dll.popBack();

    dll.print();

    return 0;
}