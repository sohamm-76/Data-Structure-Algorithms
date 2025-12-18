#include<iostream>
using namespace std;

void printArr(int nums[], int n){
    cout << sizeof(nums) << endl;//8 is size of int pointer
    for(int i = 0; i<n; i++){
        cout << nums[i] << ","; 
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout << "array size = " << sizeof(arr) << endl;
    printArr(arr , n);
    return 0;
}