#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        pq.push(a+b);
        sum += a+b;
    }

    cout << sum;
    return 0;
}