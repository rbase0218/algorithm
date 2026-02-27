#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k = n / 2;
    cout << k << '\n';
    
    for (int i = 0; i < k; ++i) {
        nums[i] += 1e4 * (k - i + 1);
        nums[n - i - 1] -= 1e4 * (k - i + 1);

        for (int j = 0; j < n; j++) {
            cout << nums[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}