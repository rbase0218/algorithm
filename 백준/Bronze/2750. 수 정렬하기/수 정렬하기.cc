#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> num(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (num[i] > num[j])
            {
                int temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << num[i] << '\n';
    }

    return 0;
}