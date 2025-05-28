#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int maps[2201][2201];
int a = 0, b = 0, c = 0;

void find(int x, int y, int size) {
	int select = maps[y][x];
	bool same = true;

	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (maps[i][j] != select) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}

	if (same) {
		switch (select) {
		case 0:
			a++;
			break;
		case -1:
			b++;
			break;
		case 1:
			c++;
			break;
		}
	}
	else {
		int nextSize = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				find(x + j * nextSize, y + i * nextSize, nextSize);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> maps[i][j];
		}
	}
	find(1, 1, n);
	cout << b << "\n" << a << "\n" << c << "\n";
	return 0;
}