#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    int ans = 0;
    bool isWord = false;

    getline(cin, text);

    text += ' ';
    for (char c : text) {
        if (c == ' ') {
            if (isWord) isWord = !isWord;
        }
        else {
            if (!isWord) {
                isWord = true;
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}