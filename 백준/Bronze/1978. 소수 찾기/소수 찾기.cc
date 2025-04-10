#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_prime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i < n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main(void) {
    int n;
    cin >> n;
    vector<int> num(n);

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        if(is_prime(num[i]))
            answer += 1;
    }

    cout << answer << endl;
    return 0;
}