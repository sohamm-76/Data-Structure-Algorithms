#include <iostream>
using namespace std;

void clearBitsInRange(int num, int i, int j) {
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;

    num = num & mask;
    cout << num << endl;
}

int main() {
    clearBitsInRange(15, 1, 3); // Output: 1
    clearBitsInRange(31, 1, 3); // Output: 17
    return 0;
}