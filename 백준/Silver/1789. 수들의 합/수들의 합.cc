#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main() {
    long long s;
    int ans = 0;
    cin >> s;

    while (s > 0)
    {
        ans++;
        s -= ans;

        if (s < 0)
        {
            ans -= 1;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
