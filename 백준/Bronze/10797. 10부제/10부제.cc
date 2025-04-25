#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(5, 0);

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> num[i];
        if (num[i] == n)
            ans++;
    }
    cout << ans;

    return 0;
}