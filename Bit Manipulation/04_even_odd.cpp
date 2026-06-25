#include<iostream>
using namespace std;

void oddorEven(int num){
    if(!(num & 1)){
        cout << "even\n";
    }else{
        cout << "odd\n";
    }
}
int main(){
    oddorEven(5);
    oddorEven(8);

    return 0;
}

