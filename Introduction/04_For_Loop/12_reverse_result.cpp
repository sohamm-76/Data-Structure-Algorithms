#include<iostream>
using namespace std;
int main(){
    int n = 10829;
    int result = 0;
    while(n>0){
        int lastDig = n%10;
        result = result*10 + lastDig;
        n = n/ 10;
    }
    cout<<"reverse = "<< result << endl;
}