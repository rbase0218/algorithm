#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Sticker {
    int h, w;
};

int H, W, N;
vector<Sticker> stickers;

bool canPlace(int h1, int w1, int h2, int w2) {
    if ((h1 + h2 <= H && max(w1, w2) <= W) ||
        (max(h1, h2) <= H && w1 + w2 <= W)) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> N;
    stickers.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> stickers[i].h >> stickers[i].w;
    }

    int maxArea = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            Sticker a = stickers[i];
            Sticker b = stickers[j];

            for (int rotA = 0; rotA < 2; ++rotA) {
                for (int rotB = 0; rotB < 2; ++rotB) {
                    int aH = rotA ? a.w : a.h;
                    int aW = rotA ? a.h : a.w;
                    int bH = rotB ? b.w : b.h;
                    int bW = rotB ? b.h : b.w;

                    if (canPlace(aH, aW, bH, bW)) {
                        int area = aH * aW + bH * bW;
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
    }

    cout << maxArea << '\n';
    return 0;
}