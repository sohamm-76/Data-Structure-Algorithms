#include<iostream>
#include <climits>
using namespace std;

// void maxSubarraySum2(int *arr, int n){
//     int maxSum = INT_MIN;

//     for(int start=0;start<n;start++){//start = 2
//         int currSum =0;
//         for(int end=start;end<n;end++){//end = 2, 3, 4, 5
//             currSum += arr[end];
//             maxSum = max(maxSum,currSum);
//         }
//     }

//     cout << "maximum subarray sum = "<< maxSum << endl;
// }

void maxSubarraySum3(int *arr, int n){
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0;i<n;i++){
        currSum += arr[i];
        maxSum = max(currSum,maxSum);
        if(currSum < 0){
            currSum = 0;
        }
    }
    cout << "maximum subarray sum = "<< maxSum << endl;
}
int main(){
    int arr[4] = {-1, -2, -3,-4};
    int n = sizeof(arr)/sizeof(int);

    maxSubarraySum3(arr,n);
    return 0;
}
