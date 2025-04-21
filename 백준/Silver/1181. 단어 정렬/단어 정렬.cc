#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool cmp(string s1, string s2) {
    if (s1.length() == s2.length())
        return s1 < s2;
    else
        return s1.length() < s2.length();
}

int main() {
    int wordCount = 0;
    cin >> wordCount;
    vector<string> word(wordCount);
    
    for (int i = 0; i < wordCount; ++i) {
        cin >> word[i];
    }

    sort(word.begin(), word.end(), cmp);
    word.erase(unique(word.begin(), word.end()), word.end());

    for (int i = 0; i < word.size(); ++i) {
        cout << word[i] << '\n';
    }

    return 0;
}