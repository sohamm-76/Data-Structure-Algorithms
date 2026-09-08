// Question 1 : Write a recursive function to perform Binary Search. Input: key=5

#include<iostream>
using namespace std;

int binSearch(int arr[], int si, int ei, int key){
    //Base case key not found
    if(si > ei)
      return -1;
    
    int mid = si + (ei - si)/2;

    //key found
    if (arr[mid] == key)
      return mid;

    //search in left half
    else if(arr[mid]> key)
      return binSearch(arr, si, mid-1, key);

    //search in right half
    else
      return binSearch(arr, mid+1, ei, key);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    int key = 5;

    int index = binSearch(arr, 0 , n-1, key);

    cout << index;

    return 0;
}