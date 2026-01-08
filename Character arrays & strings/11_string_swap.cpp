#include <iostream>
#include <string>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    if (s1.length() != s2.length())
        return false;

    int diffIndex[2];  // to store at most 2 differing indices
    int diffCount = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (diffCount == 2)  // more than 2 differences → not possible
                return false;
            diffIndex[diffCount++] = i;
        }
    }

    // Case 1: Strings are already equal
    if (diffCount == 0)
        return true;

    // Case 2: Exactly two characters differ → check swap
    if (diffCount == 2) {
        int i = diffIndex[0];
        int j = diffIndex[1];
        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }

    // Case 3: Only one character differs → not possible
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;

    if (areAlmostEqual(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
