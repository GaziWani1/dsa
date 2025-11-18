#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter Size of Array";
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "You entered: \n";
    printArray(arr, n);
}