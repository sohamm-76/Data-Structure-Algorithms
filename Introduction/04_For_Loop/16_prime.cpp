#include<iostream>
using namespace std;
int main(){
    int n =9;
    bool isPrime = true;

    for(int i =2; i<=n-1; i++){
        if(n % i == 0){
            //i is a factor of n;completely divides n;n is composite number
            isPrime = false;
            break;
        }
}
if(isPrime==true){
    cout<<"Number is prime "<<endl;
}else{
    cout<<"Number is NOT Prime"<<endl;
}
return 0;
}