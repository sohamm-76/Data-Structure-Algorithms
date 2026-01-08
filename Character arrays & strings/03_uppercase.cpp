#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = word[i];
        if (ch >= 'a' && ch <= 'z')
        {
            word[i] = ch - ('a' - 'A'); // convert to uppercase
        }
    }
}

int main()
{
    char word[] = "ApPle";
    toUpper(word, strlen(word));
    cout << word << endl; // Output: APPLE
    return 0;
}
