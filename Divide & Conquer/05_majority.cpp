#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();

    for (int num : nums) {
        count[num]++;
        if (count[num] > n / 2) {
            return num; // found majority early
        }
    }

    return -1; // should never reach here because majority always exists
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << majorityElement(nums) << endl;

    return 0;
}
