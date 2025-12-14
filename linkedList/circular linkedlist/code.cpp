#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList()
    {
        head = tail = NULL;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            tail->next = head;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
        return;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        return;
    }

    void deleteAtHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        Node *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail()
    {

        if (head == NULL && tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        Node *temp = tail;
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        tail = prev;
        tail->next = head;
        temp->next = NULL;

        delete temp;
    }

    void printList()
    {

        cout << head->data << "-> ";
        Node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int ele)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == ele)
            {
                cout << temp->data << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "ele not founf in the list" << endl;
    }
};

int main()
{
    CircularList ll;
    ll.insertAtHead(1);
    ll.insertAtHead(2);
    ll.insertAtHead(3);
    ll.insertAtHead(188);

    ll.printList();
    ll.insertAtTail(9);
    ll.printList();
    ll.deleteAtHead();
    ll.printList();
    ll.deleteAtTail();
    ll.printList();

    return 0;
}