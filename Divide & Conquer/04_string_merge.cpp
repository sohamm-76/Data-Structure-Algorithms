#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<string>& arr, int si, int mid, int ei) {
    vector<string> temp;
    int i = si;
    int j = mid + 1;

    // Merge two sorted halves
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {   // Lexicographic comparison
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Remaining elements in left half
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Remaining elements in right half
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); ++k) {
        arr[si + k] = temp[k];
    }
}

void mergeSort(vector<string>& arr, int si, int ei) {
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

void printArr(const vector<string>& arr) {
    for (auto s : arr) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    vector<string> arr = {"sun", "earth", "mars", "mercury"};

    cout << "Before Sorting: ";
    printArr(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "After Sorting:  ";
    printArr(arr);

    return 0;
}
