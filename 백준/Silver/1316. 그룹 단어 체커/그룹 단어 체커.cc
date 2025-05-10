#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    string text;
    while (n--) {
        cin >> text;
        bool isGroupWord = true;
        string temp = "";

        for (int i = 0; i < text.size(); ++i) {
            bool exists = temp.find(text[i]) != string::npos;

            if (exists && (i == 0 || text[i] != text[i - 1])) {
                isGroupWord = false;
                break;
            }

            if (!exists) {
                temp += text[i];
            }
        }

        if (isGroupWord) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}