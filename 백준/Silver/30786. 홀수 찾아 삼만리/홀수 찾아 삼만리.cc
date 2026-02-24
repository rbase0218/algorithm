#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	int n, x, y;
	cin >> n;
	
	vector<int> odd, even;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;

		if ((x + y) % 2 == 0) even.push_back(i + 1);
		else odd.push_back(i + 1);
	}

	if (!even.size() || !odd.size()) cout << "NO";
	else
	{
		cout << "YES" << endl;
		for (auto n : odd) cout << n << " ";
		for (auto n : even) cout << n << " ";
	}

	return 0;
}