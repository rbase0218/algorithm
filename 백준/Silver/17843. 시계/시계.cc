#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    cout << fixed << setprecision(10);

    while (t--) {
        int h, m, s;
        cin >> h >> m >> s;

        int arr[3];
        arr[0] = 3600 * h + 60 * m + s;   
        arr[1] = 720 * m + 12 * s;        
        arr[2] = 720 * s;                 

        sort(arr, arr + 3);

        int diff1 = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        int diff3 = 43200 + arr[0] - arr[2];

        int mn = min({ diff1, diff2, diff3 });

        double angle = mn / 120.0;
        cout << angle << "\n";
    }
    return 0;
}
