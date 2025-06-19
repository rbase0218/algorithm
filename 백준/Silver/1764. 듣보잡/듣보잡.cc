#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    map<string, int> names;
    vector<string> answers;

    string ans;
    for (int i = 0; i < n+m; ++i) {
        cin >> ans;

        names[ans] += 1;

        if (names[ans] > 1)
            answers.push_back(ans);
    }

    sort(answers.begin(), answers.end());
    cout << answers.size() << '\n';
    for (auto n : answers)
    {
        cout << n << '\n';
    }
    

    return 0;
}