#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m, sum = 0;
    cin >> n >> m;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        nums[i] = (i == 1) ? nums[i] : nums[i - 1] + nums[i];
    }

    int a, b;
    while (m--) {
        cin >> a >> b;
        cout << nums[b] - nums[a - 1] << '\n';
    }

    return 0;
}