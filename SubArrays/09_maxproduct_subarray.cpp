#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProduct(vector<int>& nums){
    int maxTillNow = nums[0];
    int minTillNow = nums[0];
    int ans = nums[0];

    for(int i=1; i<nums.size(); i++){
        int curr = nums[i];

        //store maxTillNow before updating it(important for min calculation)
        int tempMax = max(curr,max(maxTillNow* curr,minTillNow* curr));
        minTillNow = min(curr, min(maxTillNow* curr,minTillNow* curr));

        maxTillNow = tempMax;//update maxTillNow
        ans = max(ans, maxTillNow);
    }
    return ans;
}

int main(){
    vector<int> nums= {2,3,-2,4};
    cout << maxProduct(nums);
    return 0;
}
