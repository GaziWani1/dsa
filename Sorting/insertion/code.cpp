#include <iostream>
using namespace std;

int main()
{
    int arr[] = {11, 2, 13, 95, 20};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > current)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}