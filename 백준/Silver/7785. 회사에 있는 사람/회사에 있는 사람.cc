#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(void)
{
	int n;
	map<string, string, greater<>> names;
	cin >> n;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string name, action;
	for (int i = 0; i < n; ++i) {
		cin >> name >> action;

		if (action == "enter")
			names[name] = action;
		else if (action == "leave")
		{
			if (names.find(name) != names.end())
				names.erase(name);
		}
	}

	for (auto n : names)
		cout << n.first << '\n';


	return 0;
}