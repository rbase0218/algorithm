#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string text, bomb_text;

	cin >> text;
	cin >> bomb_text;

	string result;
	int bombSize = bomb_text.size();

	for (char c : text) {
		result += c;

		if (result.size() >= bombSize && result.substr(result.size() - bombSize) == bomb_text)
			result.erase(result.size() - bombSize);
	}

	cout << (result.empty() ? "FRULA" : result) << endl;

	return 0;
}