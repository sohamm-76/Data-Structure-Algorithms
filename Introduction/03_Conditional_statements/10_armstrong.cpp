#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a 3 digit number:";
    cin>>n;

    int num = n;//creating a copy

    int dig1 = num%10;
    num/=10;
    int dig2 = num%10;
    num/=10;
    int dig3 = num;

    int cubesum =dig1*dig1*dig1 + dig1*dig1*dig1 + dig1*dig1*dig1;

    return 0;
}