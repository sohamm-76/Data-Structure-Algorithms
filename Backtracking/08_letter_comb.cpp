// leetcode problem no 17 : Letter combinations of a phone number

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string mapping[10] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void keypad(string digits, int idx, string ans){
    //BC: ALl digits reserved
    if(idx == digits.length()) {
        cout << ans << endl;
        return;
    }
    //Get letters corresponding to the current digit
    string letters = mapping[digits[idx] - '0'];

    //Explore all possible letters
    for(int i = 0; i<letters.length(); i++){
        keypad(digits, idx+1, ans + letters[i]);
    }
}
int main(){

    string digits = "23";

    cout << "Starting recursion..." << endl;
    if(digits.length() == 0){
        return 0;
    }

    keypad(digits, 0, "");

    return 0;
}