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
    int n;
    long long sum = 0;
    cin >> n;

    vector<long long> num(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        total += num[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        total -= num[i];
        sum = (sum + num[i] * total % 1000000007) % 1000000007;
    }

    cout << sum;

    return 0;
}
