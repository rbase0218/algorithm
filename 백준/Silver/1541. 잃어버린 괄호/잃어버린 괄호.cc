#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    string val;
    cin >> val;

    string num = "";
    bool checked = false;
    int ans = 0;

    for (int i = 0; i <= val.size(); ++i) {
        if (val[i] == '-' || val[i] == '+' || i == val.size())
        {
            if (checked)
                ans -= stoi(num);
            else
                ans += stoi(num);

            num = "";
        }
        else
            num += val[i];

        if (val[i] == '-')
            checked = true;
    }

    cout << ans;

    return 0;
}