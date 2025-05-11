#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits> 
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken_shops;
vector<bool> selected;

int getDistance(pair<int, int> pos1, pair<int, int> pos2) {
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

int getCityChickenDistance() {
    int total_distance = 0;

    for (auto& house : houses) {
        int min_distance = INT_MAX;
        for (int i = 0; i < chicken_shops.size(); i++) {
            if (selected[i]) {
                int distance = getDistance(house, chicken_shops[i]);
                min_distance = min(min_distance, distance);
            }
        }
        total_distance += min_distance;
    }

    return total_distance;
}

int selectChickenShops(int index, int count) {
    if (count == M) {
        return getCityChickenDistance();
    }

    if (index == chicken_shops.size()) {
        return INT_MAX;
    }

    int min_distance = INT_MAX;

    selected[index] = true;
    min_distance = min(min_distance, selectChickenShops(index + 1, count + 1));

    selected[index] = false;
    min_distance = min(min_distance, selectChickenShops(index + 1, count));

    return min_distance;
}

int main() {
    cin >> N >> M;

    int value;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> value;
            if (value == 1) {  
                houses.push_back({ i, j });
            }
            else if (value == 2) { 
                chicken_shops.push_back({ i, j });
            }
        }
    }

    selected.resize(chicken_shops.size(), false);

    int min_city_distance = selectChickenShops(0, 0);

    cout << min_city_distance << endl;

    return 0;
}