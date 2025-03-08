#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        int n;
        cin >> n;

        for (int i = n / 2; i >= 2; i--) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << n - i << '\n';
                break;
            }
        }
    }

    return 0;
}