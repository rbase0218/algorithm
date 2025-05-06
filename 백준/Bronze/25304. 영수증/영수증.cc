#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int acount, count;
	pair<int, int> item;
	cin >> acount >> count;
	while (count--) {
		cin >> item.first >> item.second;

		acount -= (item.first * item.second);
	}

	cout << ((acount == 0) ? "Yes" : "No") << endl;

	return 0;
}