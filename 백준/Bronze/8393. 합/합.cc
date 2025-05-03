#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    int n, ans = 0;
    cin >> n;

    n += 1;
    while (--n) {
        ans += n;
    }

    cout << ans;

    return 0;
}