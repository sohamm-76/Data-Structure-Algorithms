#include<iostream>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest){

    if(n == 1){
        cout << "transfer disk " << n << " from " << src << " to " << dest << endl;

        return;    }


    //transfer top n-1 from src to helper using dest as helper
    towerOfHanoi(n-1, src, dest, helper);

    //tranfer nth from src to dest
    cout << "transfer disk " << n << " from " << src << " to " << dest << endl;

    //transfer n-1 from helper to dest using src as helper
    towerOfHanoi(n-1, helper, src, dest);
}

int main(){
    int n = 4;

    towerOfHanoi(4, "A", "B", "C");

    return 0;
}