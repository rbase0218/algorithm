#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N; // 지도의 크기
vector<vector<int>> map; // 지도
vector<vector<bool>> visited; // 방문 여부
vector<int> complex_sizes; // 각 단지별 집의 수

// 상하좌우 이동을 위한 방향 벡터
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

// BFS를 통한 단지 탐색
int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;
    int count = 1; // 현재 집 포함

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 지도 범위 내에 있는지 확인
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                // 방문하지 않았고 집이 있는 경우
                if (!visited[nx][ny] && map[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                    count++; // 집의 수 증가
                }
            }
        }
    }

    return count;
}

int main() {
    // 입력 처리
    cin >> N;

    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    // 지도 정보 입력
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    // 모든 지점에 대해 단지 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int size = bfs(i, j);
                complex_sizes.push_back(size);
            }
        }
    }

    // 단지 내 집의 수 오름차순 정렬
    sort(complex_sizes.begin(), complex_sizes.end());

    // 결과 출력
    cout << complex_sizes.size() << endl; // 총 단지 수
    for (int size : complex_sizes) {
        cout << size << endl; // 각 단지의 집의 수
    }

    return 0;
}