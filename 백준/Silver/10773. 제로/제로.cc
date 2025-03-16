#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int count = 0, answer = 0;
	cin >> count;

	int num;
	for (int i = 0; i < count; ++i) {
		cin >> num;

		if (num == 0) {
			answer -= s.top();
			s.pop();
		}
		else {
			s.push(num);
			answer += num;
		}
	}

	cout << answer << endl;

	return 0;
}