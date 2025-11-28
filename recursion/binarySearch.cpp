#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int ele)
{
    if (l > h)
        return -1;

    int mid = l + (h - l) / 2;

    if (ele == arr[mid])
        return mid;

    if (ele < arr[mid])
        return binarySearch(arr, l, mid - 1, ele);
    else
        return binarySearch(arr, mid + 1, h, ele);
}

int main()
{
    const int n = 10;
    int arr[n] = {10, 15, 20, 22, 28, 30, 40, 45, 48, 50};
    int ele = 40;
    int find = binarySearch(arr, 0, n - 1, ele);
    cout << find << endl;
}