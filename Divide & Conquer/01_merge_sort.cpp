#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    vector<int> temp;

    int i = si;
    int j = mid + 1;

    // Merge two sorted halves into temp
    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // Remaining left half
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    // Remaining right half
    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    // Copy temp back to original array from si..ei
    for (int idx = si, x = 0; idx <= ei; ++idx)
    {
        arr[idx] = temp[x++];
    }
}

void mergeSort(int arr[], int si, int ei) // O(n log n)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);     // left half
    mergeSort(arr, mid + 1, ei); // right half

    merge(arr, si, mid, ei); // merge (conquer)
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;

    cout << "Before: ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After:  ";
    printArr(arr, n);

    return 0;
}
