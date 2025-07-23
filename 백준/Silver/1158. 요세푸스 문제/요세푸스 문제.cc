#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> re;
	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	int flag = 1;
	while (!q.empty())
	{
		int val = q.front();
		q.pop();

		if (flag == k)
		{
			flag = 1;
			re.push_back(val);
		}
		else
		{
			q.push(val);
			flag++;
		}
	}

	cout << "<";
	for (int i = 0; i < n; ++i) {
		cout << re[i];
		if (i != n - 1) cout << ", ";
	}
	cout << ">";

	return 0;
}