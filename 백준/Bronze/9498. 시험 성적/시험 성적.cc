#include <iostream>
using namespace std;

int main(void) {
    int n;
    char result = 'A';

    cin >> n;
    n = n / 10;

    if (n >= 9)
        result = 'A';
    else if (n >= 8)
        result = 'B';
    else if (n >= 7)
        result = 'C';
    else if (n >= 6)
        result = 'D';
    else
        result = 'F';

    cout << result << endl;

    return 0;
}