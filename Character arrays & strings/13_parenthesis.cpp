#include <iostream>
using namespace std;

bool isValid(string s) {
    char arr[1000];  // manual stack
    int top = -1;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
            arr[++top] = c;      // push
        else {
            if (top == -1) return false; // empty → invalid
            char open = arr[top--];      // pop
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '['))
                return false;
        }
    }
    return top == -1; // all opened are closed
}

int main() {
    string s;
    cin >> s;
    cout << (isValid(s) ? "true" : "false");
}
