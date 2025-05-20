#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	map<string, int> names;
	vector<string> indexies;
	string ans;

	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 1; i <= n; ++i) {
		cin >> ans;
		names.insert(make_pair(ans, i));
		indexies.push_back(ans);
	}

	for (int i = 0; i < m; ++i) {
		cin >> ans;

		if (names.find(ans) != names.end())
			cout << names[ans] << '\n';
		else
			cout << indexies[stoi(ans) - 1] << '\n';
	}

	return 0;
}