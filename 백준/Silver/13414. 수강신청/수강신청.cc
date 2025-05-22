#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>

using namespace std;

int main() {
	int k, l;
	cin >> k >> l;
	unordered_map<string, int> students;
	map<int, string> sort_students;

	string num;
	for (int i = 0; i < l; ++i) {
		cin >> num;
		students[num] = i;
	}

	for (const auto& pair : students) {
		sort_students[pair.second] = pair.first;
	}
	for (const auto& pair : sort_students)
	{
		cout << pair.second << '\n';

		k--;
		if (k < 1)
			break;
	}

	return 0;
}