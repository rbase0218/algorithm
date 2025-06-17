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
	queue<int> num;
	for (int i = 1; i <= n; ++i) {
		num.push(i);
	}

	while (num.size() != 1)
	{
		num.pop();
		int temp = num.front();
		num.pop();
		num.push(temp);
	}

	cout << num.front();
	
	return 0;
}