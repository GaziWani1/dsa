#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int place)
{
    int freqArray[10] = {0};

    for (int i = 0; i < n; i++)
        freqArray[(arr[i] / place) % 10]++;

    // CUMULATIVE FREQUENCE
    for (int i = 1; i < 10; i++)
    {
        freqArray[i] += freqArray[i - 1];
    }

    int ans[n];

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        ans[--freqArray[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int place = 1; max / place > 0; place *= 10)
        countSort(arr, n, place);
}

int main()
{
    const int n = 10;
    int arr[n] = {12, 48, 21, 30, 17, 93, 880, 69, 72, 53};

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
