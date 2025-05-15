#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int getClockNum(int a, int b, int c, int d) {
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;

    return min({ num1, num2, num3, num4 });
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int card_clock_num = getClockNum(a, b, c, d);

    int count = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                for (int l = 1; l <= 9; l++) {
                    int current_clock_num = getClockNum(i, j, k, l);
                    if (current_clock_num == i * 1000 + j * 100 + k * 10 + l) {
                        if (current_clock_num <= card_clock_num) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    cout << count;
    return 0;
}