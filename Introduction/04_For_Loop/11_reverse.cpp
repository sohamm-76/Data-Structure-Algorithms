#include<iostream>
using namespace std;
int main(){
     int n =12345;

     while(n>0){
        int lastDig = n%10;
        cout<<lastDig;
        n/=10;
     }

     cout<<endl;
     return 0;
}