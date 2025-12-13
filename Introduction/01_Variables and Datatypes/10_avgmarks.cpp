#include<iostream>
using namespace std;

int main(){
    int sci;
    int eng;
    int math;

    cout<<"enter science marks: ";
    cin>>sci;

    cout<<"enter english marks: ";
    cin>>eng;

    cout<<"enter math marks: ";
    cin>>math;

    int avg = (sci +eng + math)/3;
    cout<<"avg marks = "<<avg<<endl;
    return 0;
}