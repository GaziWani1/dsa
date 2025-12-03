#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient
{
public:
    string name;
    int prority;
    Patient(string name, int prority)
    {
        this->name = name;
        this->prority = prority;
    }
};

class MaxHeap
{
public:
    int capacity;
    int size;
    vector<Patient> heap;

    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(Patient p)
    {
        if (size >= capacity)
        {
            cout << "Heap is full!" << endl;
            return;
        }

        heap.push_back(p);
        size++;
        heapifyUp(size - 1);
    }

    void heapifyUp(int i)
    {
        while (i != 0 && heap[parent(i)].prority < heap[i].prority)
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l].prority > heap[largest].prority)
            largest = l;
        if (r < size && heap[r].prority > heap[largest].prority)
            largest = r;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    Patient extractMax()
    {
        if (size == 0)
        {
            return Patient("", -1);
        }

        Patient maxPatient = heap[0];
        heap[0] = heap[size - 1];
        heap.pop_back();
        size--;
        heapifyDown(0);
        return maxPatient;
    }

    void printHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << "(" << heap[i].name << ", " << heap[i].prority << ") ";
        }
        cout << endl;
    }
};

int main()
{

    MaxHeap mxheap(4);
    mxheap.insert(Patient("Mosin", 5));
    mxheap.insert(Patient("Abid", 3));
    mxheap.insert(Patient("Asif", 8));
    mxheap.insert(Patient("Alia", 1));

    cout << "Heap: ";
    mxheap.printHeap();

    Patient deleted = mxheap.extractMax();
    cout << "Deleted patient with highest priority: ("
         << deleted.name << ", " << deleted.prority << ")" << endl;

    cout << "Heap after deletion: ";
    mxheap.printHeap();

    return 0;
}