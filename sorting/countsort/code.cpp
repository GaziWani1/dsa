#include <iostream>
using namespace std;

void countSort(int max, int arr[], int n)
{
    int cntArr[max + 1];
    int ans[n];
    for (int i = 0; i <= max; i++)
    {
        cntArr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cntArr[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        cntArr[i] += cntArr[i - 1];
    }

    // for (int i = 0; i < max; i++)
    //     cout << cntArr[i] << " ";

    for (int i = n - 1; i >= 0; i--)
    {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}

int main()
{
    const int n = 8;
    int arr[n] = {2, 5, 3, 0, 2, 3, 0, 3};
    int max = 5;
    countSort(max, arr, n);
    return 0;
}