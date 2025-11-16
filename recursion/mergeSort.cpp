#include <iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end)
{
    // cout << "ST :" << st << " MID : " << mid << " END :" << end << endl;

    int n = mid - st + 1;
    int m = end - mid;
    int temp[(end - st + 1)];
    int i = st, j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    // leftover right part
    while (j <= end)
        temp[k++] = arr[j++];

    for (int x = 0; x < k; x++)
        arr[st + x] = temp[x];
}

void mergeSort(int arr[], int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, st, mid, end);     // merge
    }
}

int main()
{
    int arr[] = {5, 2, 3, 4, 1, 10, 8, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
