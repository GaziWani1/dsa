#include <iostream>
using namespace std;

int partion(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pivot = partion(arr, l, h);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
    }
}

int main()
{
    const int n = 10;
    int arr[n] = {10,
                  16,
                  8,
                  12,
                  15,
                  6,
                  3,
                  9,
                  5,
                  0};
    int l = 0;
    int h = n - 1;
    // int partEle = partion(arr, l, h);
    quickSort(arr, l, h);
    printArray(arr, n);
}