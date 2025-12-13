#include<iostream>
using namespace std;
int main(){
    // int a;
    // cout<<"Enter value of a:";
    // cin>>a;

    // int b;
    // cout<<"Enter value of b:";
    // cin>>b;

    // if(a>b){
    //     cout<<"a is larger than b"<<endl;
    // }else{
    //     cout<<"b is larger than a"<<endl;
    // }
    int num;
    cout<<"Enter number:";
    cin>>num;

    if(num %2 ==0){
        cout<<"number is even"<<endl;
    }else{
        cout<<"number is odd"<<endl;
    }

    return 0;
}