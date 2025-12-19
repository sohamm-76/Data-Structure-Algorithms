#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;

    while(low<=high){
        int mid = (low+high)/2;

        //check if target is found
        if(nums[mid] == target)
           return mid;

        //check if left half is sorted
        if(nums[low] <= nums[mid]){
            //if target lies within the sorted left half
            if(nums[low] <= target && target < nums[mid])
               high = mid - 1;
            else
               low = mid + 1;
        }
        //Otherwise right half will be sorted
        else{
            //If target lies within the sorted right half 
            if(nums[mid] < target && target <= nums[high])
               low = mid + 1;
            else
               high = mid - 1;
        }
    }
    return -1;//not found
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int index = search(nums,target);
    cout << index;

    return 0;
}