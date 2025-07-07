#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    char result;

    for (int i = 0; i < 4; i++) {
        int x1, y1, p1, q1, x2, y2, p2, q2;
        cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;


        if (p1 < x2 || p2 < x1 || q1 < y2 || q2 < y1)
            result = 'd';
        else if ((p1 == x2 && q1 == y2) || (p1 == x2 && y1 == q2) || (x1 == p2 && q1 == y2) || (x1 == p2 && y1 == q2))
            result = 'c';
        else if (p1 == x2 || x1 == p2 || q1 == y2 || y1 == q2)
            result = 'b';
        else
            result = 'a';

        cout << result << '\n';
    }

    return 0;
}