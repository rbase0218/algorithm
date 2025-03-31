#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    long long number = 666;

    while (count < n) {
        string str = to_string(number);

        if (str.find("666") != string::npos) {
            count++;
        }

        if (count == n) {
            cout << number;
            break;
        }

        number++;
    }

    return 0;
}