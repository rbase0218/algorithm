#include<iostream>
#include<vector>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x, int y, vector<vector<int>>& arr) {
	arr[x][y] = 0;

	for (int n = 0; n < 4; n++) {
		int r = x + dx[n];
		int c = y + dy[n];
		if (r >= 0 && r < arr.size() && c >= 0 && c < arr[0].size() && arr[r][c] == 1) {
			dfs(r, c, arr);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int M, N, K;
		cin >> M >> N >> K;
		vector<vector<int>> arr(N, vector<int>(M, 0));

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> y >> x;
			arr[x][y] = 1;
		}

		int count = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[j][k] == 1) {
					count++;
					dfs(j, k, arr);
				}
			}
		}
		cout << count << "\n";
	}
}