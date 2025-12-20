#include<iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[],int n){
    bool isSwap = false;
    cout << "outer loop";
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){//ascending
                // if(arr[j] < arr[j+1]) descending
                swap(arr[j],arr[j+1]);
                isSwap = true;
                cout << "inner loop";    
            }
        }
        if(!isSwap){
            //array is already sorted
            return;
        }
    }

    print(arr,n);
}

int main(){
    // int arr[5] = {5,4,3,2,1};
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    bubbleSort(arr,10);
    cout << endl;

    return 0;
}