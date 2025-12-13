#include<iostream>
using namespace std;
int main(){
    int a,b;
    char op;

    cout<<"enter a:";
    cin>>a;
    cout<<"enter b:";
    cin>>b;
    cout<<"enter operator : ";
    cin>>op;


    //Calculator
    // if(op == '+'){
    //     cout<<"a + b = "<< (a+b)<< endl;
    // }else if(op == '-'){
    //     cout<<"a - b = "<<(a-b)<<endl;
    // }else if(op == '*'){
    //     cout<<"a * b = "<<(a*b)<<endl;
    // }else if(op == '/'){
    //     cout<<"a / b = "<<(a/b)<<endl;
    // }else{
    //     cout<<"Invalid Operator";
    // }

    //Switch
    switch(op){
        case '+' :cout<<"a + b = "<< (a+b)<< endl;
        break;
        case '-' :cout<<"a - b = "<<(a-b)<<endl;
        break;
        case '*' :cout<<"a * b = "<<(a*b)<<endl;
        break;
        case '/' :cout<<"a / b = "<<(a/b)<<endl;
        default  :cout<<"Invalid Operator";
    }

    return 0;
}