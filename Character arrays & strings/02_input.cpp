#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // char word[30];

    // cout << "Enter a word: ";
    // cin >> word;//ignore whitespace

    // cout << "your word was: " << word << endl;
    // cout << "length : " << strlen(word) << endl;

    char sentence[30];
    cout << "Enter sentence: ";
    cin.getline(sentence,30, '*');

    cout << "your sentence was: " << sentence << endl;
    cout << "length : " << strlen(sentence) << endl;
    return 0;
}