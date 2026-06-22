#include <iostream>
#include <vector>
using namespace std;

int pow(int x, int n){
    if(n == 0){
        return 1;
    }

    // x^n/2
    int halfPow = pow(x, n/2);
    int halfPowsquare = halfPow * halfPow;

    if(n % 2 != 0){
        //odd
        return x * halfPowsquare;
    }
    return halfPowsquare;
}
int main(){
    cout << pow(2,5) << endl;
    return 0;
}