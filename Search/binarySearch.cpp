#include <iostream>
using namespace std;

int binarySearch(int arr[], int n)
{
    int st = 0, end = n - 1, target = 99;
    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (target > arr[mid])
            st = mid + 1;
        if (target < arr[mid])
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchRec(int arr[], int st, int end, int target)
{
    if (st > end)
        return -1;

    int mid = (st + end) / 2;

    if (target == arr[mid])
        return mid;
    else if (target > arr[mid])
        return binarySearchRec(arr, mid + 1, end, target);
    else
        return binarySearchRec(arr, st, mid - 1, target);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    // int mid = binarySearch(arr, n);
    int mid = binarySearchRec(arr, 0, n - 1, 9);
    cout << mid << endl;
    return 0;
}