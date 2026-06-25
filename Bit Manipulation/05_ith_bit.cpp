#include<iostream>
using namespace std;

int getIthBit(int num, int i){
    int bitMask = 1 << i;

    if(!(num & bitMask)){
        return 0;
    }else{
        return 1;
    }
}

int setIthBit(int num, int i){
    int bitMask = 1 << i;
    return (num | bitMask);
}

int clearIthBit(int num, int i){
    int bitMask = ~(1 << i);
    return num & bitMask;
}

int main(){
    cout << getIthBit(6, 2) << endl;
    cout << setIthBit(6, 3) << endl;
    cout << clearIthBit(6, 1) << endl;
    return 0;
}