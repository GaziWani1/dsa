#include <iostream>
using namespace std;

void dnfSort(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    cout << "O's count :: " << count0 << endl;
    cout << "1's count :: " << count1 << endl;
    cout << "1's count :: " << count2 << endl;

    int idx = 0;

    for (int j = 0; j < count0; j++)
    {
        arr[idx++] = 0;
    }

    for (int j = 0; j < count1; j++)
    {
        arr[idx++] = 1;
    }

    for (int j = 0; j < count2; j++)
    {
        arr[idx++] = 2;
    }
    // 0(n)
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n = 11;
    int arr[11] = {1, 0, 0, 1, 1, 2, 2, 1, 0, 0, 0};
    dnfSort(arr, n);
    printArray(arr, n);
    return 0;
}