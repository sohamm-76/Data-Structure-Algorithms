#include<iostream>
using namespace std;

//pass by reference using Pointer

// void changeA(int *ptr){
//     *ptr = 20;
//     cout << *ptr << "\n";
// }

// int main(){
//     int a = 10;
//     int &b = a;
//     b= 25;

//     cout << b << "\n";
//     cout << a << "\n";
//     return 0;
// }

//pass by reference using pointer variable

void changeA(int &param){
    param = 20;
    cout << param << "\n";
}

int main(){
    int a =10;
    changeA(a);
    cout << a << "\n";
    return 0;
}