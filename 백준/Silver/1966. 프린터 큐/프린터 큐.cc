#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	int n, m;
	while (tc--) {
		// n : 문서의 개수
		// m : 궁금한 문서
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int val;
		for (int i = 0; i < n; ++i) {
			cin >> val;
			q.push({ i, val });
			pq.push(val);
		}

		int count = 0;
		while (!q.empty())
		{
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();

			if (val == pq.top())
			{
				pq.pop();
				count++;
				if (idx == m)
				{
					cout << count << '\n';
					break;
				}
			}
			else
				q.push({ idx, val });
		}

	}
	return 0;
}