#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void)
{
	int n, ans = 0;
	cin >> n;
	
	string text;
	unordered_map<string, int> ids;
	
	while (n--) {
		cin >> text;

		if (text == "ENTER")
		{
			ids.clear();
			continue;
		}

		if (ids[text] == 0)
		{
			ids[text]++;
			ans++;
		}
	}

	cout << ans;

	return 0;
}