#include<iostream>
#include<string>
using namespace std;

int main(){
    string str = "sohamyeola";

    for(char ch : str){
        cout << ch << ",";
    }
    cout << endl;
    return 0;
}