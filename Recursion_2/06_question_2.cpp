// Question 2 : For a given integer array of size N. You have to find all the occurrences
// (indices) of a given element (Key) and print them.
// Use a recursive function to solve this problem.

#include<iostream>
using namespace std;

void allOccurrences(int arr[], int key, int i, int n){
    //base case
    if(i == n)
      return;

    //If key is found
    if(arr[i] == key)
      cout << i << "";
    
    //Check next index
    allOccurrences(arr, key ,i+1 ,n);
}

int main(){
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n = 9;
    int key = 2;

    allOccurrences(arr, key, 0, n);

    return 0;
}