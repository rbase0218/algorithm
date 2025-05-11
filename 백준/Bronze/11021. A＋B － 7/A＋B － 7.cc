#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	int s = 1;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << "Case #" << s << ": " << a + b << '\n';

		s++;
	}
	return 0;
}