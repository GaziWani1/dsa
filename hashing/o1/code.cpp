#include <iostream>
using namespace std;

class Node
{
public:
    char *key;
    char *value;
    Node *next;

    Node(char *key, char *value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashMap
{
private:
    int capacity;
    int size;
    Node **table;

public:
    HashMap(int capacity = 5)
    {
        this->capacity = capacity;
        this->size = 0;

        table = new Node *[capacity];
        for (int i = 0; i < capacity; i++)
            table[i] = nullptr;
    }

    int hashFunction(char *key)
    {
        int sum = 0;
        int factor = 31;

        for (int i = 0; i < strlen(key); i++)
        {
            cout << key[i] << endl;
            sum = (sum + (key[i] * factor) % capacity) % capacity;
            factor = (factor * 31) % 32767;
        }

        return sum;
    }

    void insert(char *key, char *value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        // No collision
        if (table[index] == nullptr)
        {
            table[index] = newNode;
        }
        else
        { // Collision -> insert at head of list
            newNode->next = table[index];
            table[index] = newNode;
        }

        size++;
    }

    // Search a key
    char *search(char *key)
    {
        int index = hashFunction(key);
        Node *curr = table[index];

        while (curr != nullptr)
        {
            if (strcmp(curr->key, key) == 0)
                return curr->value;
            curr = curr->next;
        }

        return (char *)"Oops! No data found.";
    }

    void printTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "Bucket " << i << ": ";

            Node *curr = table[i];
            while (curr != nullptr)
            {
                cout << curr->key << " -> ";
                curr = curr->next;
            }

            cout << "NULL\n";
        }
    }
};

int main()
{
    HashMap mp;
    mp.insert((char *)"Yogaholic", (char *)"Anjali");
    // mp.insert((char *)"pluto14", (char *)"Vartika");
    // cout << mp.search((char *)"Yogaholic") << endl;
    // mp.printTable();
    return 0;
}