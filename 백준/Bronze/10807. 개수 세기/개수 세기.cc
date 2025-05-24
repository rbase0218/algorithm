#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() 
{
	int n, ans;;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cin >> ans;

	n = 0;
	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == ans)
		{
			n++;
		}
	}
	
	cout << n;

	return 0;
}