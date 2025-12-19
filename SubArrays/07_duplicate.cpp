#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector<int>&nums){
    sort(nums.begin(),nums.end());//sort the array
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]==nums[i]){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int>nums={1,2,3,4,1};

    if(containsDuplicate(nums))
    cout << "true";
    else
    cout << "fasle";

    return 0;
}