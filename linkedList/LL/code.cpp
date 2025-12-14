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

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void pushFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        return;
    }

    void pushBack(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return;
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void popBack()
    {

        if (head == NULL && tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next == tail)
            {
                temp->next = NULL;
                tail = temp;
                delete temp->next;
            }
            temp = temp->next;
        }
    }

    void deleteNode(int ele)
    {
        Node *temp = head;
        while (temp != NULL)
        {

            if (temp->next->data == ele)
            {
                temp->next = temp->next->next;
                return;
            }
            temp = temp->next;
        }
        cout << "ele not founf in the list" << endl;
        return;
    }

    void insertEle(int val, int pos)
    {
        int k = 0;
        Node *temp = head;
        if (pos < 0)
            return;
        if (pos == 0)
        {
            this->pushFront(val);
            return;
        }
        Node *newNode = new Node(val);
        while (temp != NULL)
        {
            k++;
            if (pos == k)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }

            temp = temp->next;
        }
        cout << endl;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
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
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushBack(4);
    ll.pushBack(5);
    // ll.printList();
    // ll.deleteNode(2);
    // ll.popFront();
    // ll.printList();
    // ll.popBack();
    ll.printList();
    ll.insertEle(7, 2);
    ll.insertEle(9, 0);
    ll.printList();
    ll.search(70);

    return 0;
}