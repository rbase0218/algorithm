#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> map[100][100]; // first: 높이, second: 방문 여부
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y, int height)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    map[y][x].second = 1; // 시작점 방문 표시

    while (!q.empty())
    {
        pair<int, int> value = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = value.first + dx[i];
            int nextY = value.second + dy[i];

            // 범위 체크 수정: >= n으로 변경
            if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
            // 이미 방문했거나 물에 잠긴 지역 스킵
            if (map[nextY][nextX].second == 1 || map[nextY][nextX].first <= height) continue;

            map[nextY][nextX].second = 1; // 방문 표시
            q.push({ nextX, nextY });
        }
    }
}

int main(void) {
    cin >> n;

    int maxHeight = 0; // 입력된 지역 중 최대 높이 저장
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            cin >> map[y][x].first;
            map[y][x].second = 0;
            maxHeight = max(maxHeight, map[y][x].first);
        }
    }

    // BFS 방문
    int maxSafeAreas = 1; // 비가 전혀 오지 않을 때는 모든 지역이 안전(1개 영역)

    // 모든 가능한 높이에 대해 테스트
    for (int height = 0; height < maxHeight; ++height)
    {
        // Height 별 초기화
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                map[y][x].second = 0;
            }
        }

        int safeAreas = 0;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                // 여기서 높이 비교 수정: 현재 테스트 중인 height와 비교
                if (map[y][x].second == 0 && map[y][x].first > height)
                {
                    bfs(x, y, height);
                    safeAreas++;
                }
            }
        }

        maxSafeAreas = max(maxSafeAreas, safeAreas);
    }

    cout << maxSafeAreas;
    return 0;
}