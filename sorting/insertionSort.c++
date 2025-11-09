#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) // O (n^2)
{
    for (int i = 0; i < n; i++)
    {
        int currentEle = arr[i];
        int prev = i - 1;
        while (prev >= 0 && currentEle < arr[prev])
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev + 1] = currentEle;
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {42, 10, 12, 23, 35};
    int n = 5;
    insertionSort(arr, n);
    printArr(arr, n);
    return 0;
}