#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    cout << "factorial(" << n << ") = " << fact << endl;
    return fact;
}

int main()
{
    factorial(6);
    return 0;
}