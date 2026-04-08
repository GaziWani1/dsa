#include <iostream>
using namespace std;

int main()
{
    int arr[] = {11, 2, 13, 95, 20};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}