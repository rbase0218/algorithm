#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k, ans = 0, i;
    cin >> n >> k;
    vector<int> coins(n, 0);

    for (i = n - 1; i >= 0; --i) {
        cin >> coins[i];
    }
    
    i = 0;
    while (k > 0)
    {
        if (k < coins[i])
        {
            i++;
            continue;
        }
        else
        {
            k -= coins[i];
            ans++;
        }
    }

    cout << ans;

    return 0;
}