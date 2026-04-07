#include <iostream>
using namespace std;

int main()
{
    int arr[] = {11, 2, 13, 95, 20};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int smallestIndx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIndx])
            {
                smallestIndx = j;
            }
            swap(arr[i], arr[smallestIndx]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}