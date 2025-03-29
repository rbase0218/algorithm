#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n = 0;
	pair<int, int> human[50];
	cin >> n;
	vector<int> rank(n);

	for (int i = 0; i < n; ++i) {
		cin >> human[i].first >> human[i].second;
		rank[i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j)
		{
			if (human[i].first > human[j].first && human[i].second > human[j].second) 
			{
				rank[j]++;
			}
			else if (human[i].first < human[j].first && human[i].second < human[j].second)
			{
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << rank[i] << " ";

	return 0;
}