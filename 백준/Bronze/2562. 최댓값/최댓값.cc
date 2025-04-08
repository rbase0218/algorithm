#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    const int MAX = 9;

    vector<int> num(MAX, 0);
    pair<int, int> bigNum;
    bigNum.first = 0;
    bigNum.second = 0;

    for (int i = 0; i < MAX; ++i) {
        cin >> num[i];

        if (bigNum.second < num[i])
        {
            bigNum.first = i;
            bigNum.second = num[i];
        }
    }

    cout << bigNum.second << '\n' << bigNum.first + 1;

    return 0;
}