#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100]= "abc";
    char str2[100]= "xyz";
    strcat(str1,str2);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << strcmp(str1,str2) << endl;
    return 0;
}