#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> coins = { 500, 100, 50, 10, 5, 1 };
    
    int i = 0;
    n = 1000 - n;
    while (n > 0)
    {
        if (n- coins[i] < 0)
            i++;
        else
        {
            n -= coins[i];
            ans++;
        }
    }

    cout << ans;

    return 0;
}