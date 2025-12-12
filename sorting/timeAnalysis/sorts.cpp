#include <iostream>
#include <ctime> // for clock()
using namespace std;

// ---------------- BUBBLE SORT ----------------
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------------- MERGE SORT ----------------
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------- QUICK SORT ----------------
int partitionQS(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionQS(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------- UTILITY FUNCTIONS ----------------
void copyArray(int src[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

// ---------------- MAIN ----------------
int main()
{
    int sizes[] = {100, 1000, 5000};
    int t = 3;

    for (int s = 0; s < t; s++)
    {
        int n = sizes[s];
        cout << "\n===== ARRAY SIZE: " << n << " =====\n";

        int *original = new int[n];
        generateRandom(original, n);

        int *arr1 = new int[n];
        int *arr2 = new int[n];
        int *arr3 = new int[n];

        copyArray(original, arr1, n);
        copyArray(original, arr2, n);
        copyArray(original, arr3, n);

        // ----------- Bubble Sort Timing -----------
        clock_t start = clock();
        bubbleSort(arr1, n);
        clock_t end = clock();
        cout << "Bubble Sort Time: "
             << (double)(end - start) / CLOCKS_PER_SEC << " sec\n";

        // ----------- Merge Sort Timing -----------
        start = clock();
        mergeSort(arr2, 0, n - 1);
        end = clock();
        cout << "Merge Sort Time : "
             << (double)(end - start) / CLOCKS_PER_SEC << " sec\n";

        // ----------- Quick Sort Timing -----------
        start = clock();
        quickSort(arr3, 0, n - 1);
        end = clock();
        cout << "Quick Sort Time : "
             << (double)(end - start) / CLOCKS_PER_SEC << " sec\n";

        delete[] original;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    return 0;
}
