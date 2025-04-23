#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, ans = 0;
	vector<int> k = { 5, 3 };
	cin >> n;

	int i = 0;
	while (n > 0)
	{
		if (n % 5 == 0)
		{
			ans += (n / 5);
			break;
		}
		else
		{
			n -= 3;

			if (n < 0)
				ans = -1;
			else
				ans++;
		}
	}
	
	cout << ans << endl;

	return 0;
}