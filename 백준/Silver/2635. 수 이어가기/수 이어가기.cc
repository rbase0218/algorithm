#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> num;

	for (int i = 1; i <= n; ++i) {
		vector<int> temp;
		temp.push_back(n);
		temp.push_back(i);

		for (int j = 1;; ++j) {
			// 앞이 더 작다면 음수가 된다.
			if (temp[j - 1] < temp[j])
				break;
			temp.push_back(temp[j - 1] - temp[j]);
		}
		if (temp.size() > num.size())
			num = temp;
	}

	cout << num.size() << endl;
	for (auto n : num) {
		cout << n << " ";
	}
	return 0;
}