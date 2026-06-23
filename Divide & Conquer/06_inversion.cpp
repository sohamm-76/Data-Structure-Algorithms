#include <iostream>
#include <vector>
using namespace std;

// Function to count inversions using brute force O(n^2)
int countInversions(vector<int>& arr) {
    int n = arr.size();
    int count = 0; // to store number of inversions

    // Check all pairs (i, j)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // If arr[i] > arr[j], it's an inversion
            if (arr[i] > arr[j]) {
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Example input
    vector<int> arr = {2, 4, 1, 3, 5};

    cout << "Array elements: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n\nInversion pairs:\n";

    int result = countInversions(arr);

    cout << "\nTotal Inversion Count = " << result << endl;

    return 0;
}
