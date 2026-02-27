#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 연산 횟수는 N/2의 내림값입니다.
    int K = N / 2;
    cout << K << "\n";

    // x 값을 1,000,000부터 시작해서 안쪽 쌍으로 갈수록 줄여나갑니다.
    // 이는 앞쪽은 매우 크게, 뒤쪽은 매우 작게 만들어 내림차순을 강제합니다.
    long long x = 1000000;

    for (int i = 0; i < K; i++) {
        // i번째 원소에 x를 더하고, 대칭되는 N-1-i번째 원소에서 x를 뺍니다.
        A[i] += x;
        A[N - 1 - i] -= x;

        // 각 연산이 완료된 시점의 배열 전체 상태를 출력합니다.
        for (int j = 0; j < N; j++) {
            cout << A[j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";

        // 다음 쌍에서는 x값을 줄여서 A[i] >= A[i+1]이 유지되도록 합니다.
        x -= 20000;
    }

    return 0;
}