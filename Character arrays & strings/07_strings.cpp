#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin,str,'$');//delimiter is $
    cout << str << endl;
    return 0;
}