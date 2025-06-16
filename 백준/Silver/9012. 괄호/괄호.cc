#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	string text;
	while (n--) {
		stack<char> s;
		cin >> text;

		for (int i = 0; i < text.length(); ++i)
		{
			if (s.empty())
				s.push(text[i]);
			else
			{
				if (s.top() == '(' && text[i] == ')')
					s.pop();
				else
					s.push(text[i]);
			}
		}

		if (s.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}