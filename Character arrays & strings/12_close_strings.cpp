#include <iostream>
#include <string>
using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
        return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    // Count frequency of each letter
    for (int i = 0; i < word1.size(); i++) {
        freq1[word1[i] - 'a']++;
        freq2[word2[i] - 'a']++;
    }

    // Step 1: Check if both words use the same set of characters
    for (int i = 0; i < 26; i++) {
        if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0))
            return false;
    }

    // Step 2: Sort both frequency arrays manually (simple bubble sort)
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq1[i] > freq1[j]) {
                int temp = freq1[i];
                freq1[i] = freq1[j];
                freq1[j] = temp;
            }
            if (freq2[i] > freq2[j]) {
                int temp = freq2[i];
                freq2[i] = freq2[j];
                freq2[j] = temp;
            }
        }
    }

    // Step 3: Compare sorted frequencies
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i])
            return false;
    }

    return true;
}

int main() {
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    if (closeStrings(word1, word2))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
