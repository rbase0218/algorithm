#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	vector<int> numbers(n);
	vector<int> result(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	for (int i = 0; i < n; ++i) {
		while (!s.empty() && numbers[s.top()] < numbers[i])
		{
			result[s.top()] = numbers[i];
			s.pop();
		}

		s.push(i);
	}

	for (auto i : result)
	{
		std::cout << i << " ";
	}

	return 0;
}