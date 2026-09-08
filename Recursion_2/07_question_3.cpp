//Question 3 : We are given a string S, we need to find the count of all contiguous substrings 
// starting and ending with the same character.

#include<iostream>
using namespace std;

int countSubstrs(string str, int i, int j, int n){
    //only one character
    if(n == 1)
       return 1;
    
    //no characters
    if(n <= 0)
       return 0;
    
    //count excluding first character
    int res = countSubstrs(str, i+1, j, n-1);

    //Count excluding last character
    res += countSubstrs(str, i, j-1, n-1);

    //Avoid counting middle part twice
    res -= countSubstrs(str, i+1, j-1, n-2);

    //If first & last character are same
    if(str[i] == str[j])
      res++;
    
    return res;
}

int main(){
    string str = "abcab";
    int n = str.size();

    cout << countSubstrs(str, 0 , n-1, n);

    return 0;
}