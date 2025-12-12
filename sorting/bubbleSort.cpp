#include <iostream>
#include <ctime>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void fillRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

void fillSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void fillReverse(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

double measure(int arr[], int n)
{
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    srand(time(0));

    int sizes[] = {100, 1000, 10000};

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];
        int *arr = new int[n];

        cout << "\nArray Size: " << n << "\n";

        fillRandom(arr, n);
        cout << "Random Input: " << measure(arr, n) << " seconds\n";

        fillSorted(arr, n);
        cout << "Sorted Input: " << measure(arr, n) << " seconds\n";

        fillReverse(arr, n);
        cout << "Reverse-Sorted Input: " << measure(arr, n) << " seconds\n";

        delete[] arr;
    }

    return 0;
}
