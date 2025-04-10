#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    int m;
    string text;
    while (n-- > 0)
    {
        cin >> m >> text;
        for (int i = 0; i < text.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                cout << text[i];
            }
        }
        cout << '\n';
    }
    return 0;
}