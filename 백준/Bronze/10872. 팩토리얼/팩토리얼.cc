#include <iostream>
#include <vector>
using namespace std;

int f(int num) {
    if (num <= 1)
        return 1;

    return num * f(num - 1);
}

int main(void) {
    int n;
    cin >> n;

    cout << f(n);
    return 0;
}