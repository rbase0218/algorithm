#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    return original == reversed;
}

int main(void) {
    int n;
    cin >> n;

    int ans = n;
    while (true) {
        if (isPrime(ans) && isPalindrome(ans))
        {
            break;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}