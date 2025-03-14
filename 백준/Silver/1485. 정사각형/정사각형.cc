#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<pair<int, int>> points(4);
        for (int i = 0; i < 4; i++) {
            cin >> points[i].first >> points[i].second;
        }

        vector<float> distances;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                float dx = points[i].first - points[j].first;
                float dy = points[i].second - points[j].second;
                distances.push_back(dx * dx + dy * dy);
            }
        }

        sort(distances.begin(), distances.end());

        if (distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3]
            && distances[4] == distances[5] && distances[0] > 0) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }

    return 0;
}