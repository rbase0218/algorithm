#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;

    if (n % 4 == 0 && n % 100 != 0)
        ans = 1;

    ans = (n % 400 == 0) ? 1 : ans;
    cout << ans;

    return 0;
}