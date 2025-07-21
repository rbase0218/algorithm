#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int paint(int n, int m, int firstColor, vector<string>& map)
{
	int cnt = 0;
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			// 0 : W, 1 : B
			// 시작 컬러가 W면, 짝수 W, 홀수 B
			// 시작 컬러가 B면, 짝수 B, 홀수 W
			char correctText = ((i + j) % 2 == 0) ? 
									((firstColor == 0) ? 'W' : 'B') : 
									((firstColor == 0) ? 'B' : 'W');
			if (correctText != map[n + i][m + j])
				cnt++;
		}
	}

	return cnt;
}


int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> map(n);
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}
	
	int minValue = 64;
	
	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			int w = paint(i, j, 0, map);
			int b = paint(i, j, 1, map);
			minValue = min({ minValue, w, b });
		}
	}

	cout << minValue;


	return 0;
}