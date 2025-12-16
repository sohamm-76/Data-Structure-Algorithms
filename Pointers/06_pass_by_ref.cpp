#include<iostream>
using namespace std;

//pass by reference
void changeA(int *ptr){
    *ptr = 20;
}

int main(){
    int a = 10;
    changeA(&a);

    cout << a << "\n";
    return 0;
}