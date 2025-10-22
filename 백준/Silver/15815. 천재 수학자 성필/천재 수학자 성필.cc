#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<int> st;

    for (char ch : s) 
    {
        if (isdigit(ch)) 
        {
            st.push(ch - '0');
        }
        else {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();

            int res = 0;
            if (ch == '+') res = left + right;
            else if (ch == '-') res = left - right;
            else if (ch == '*') res = left * right;
            else if (ch == '/') res = left / right;

            st.push(res);
        }
    }

    cout << st.top() << '\n';
    return 0;
}