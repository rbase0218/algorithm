#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, double> point = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F",  0.0}
    };

    double sumWeighted = 0.0; // 학점×평점 합
    double sumCredit   = 0.0; // P 제외 총 학점

    // 문제 조건상 20줄이 주어집니다.
    for (int i = 0; i < 20; ++i) {
        string subject, grade;
        double credit;
        cin >> subject >> credit >> grade;

        if (grade == "P") continue; // P는 제외

        auto it = point.find(grade);
        if (it != point.end()) {
            sumWeighted += credit * it->second;
            sumCredit   += credit;
        }
        // 그 외의 입력은 주어지지 않으므로 별도 처리 불필요
    }

    double gpa = (sumCredit == 0.0) ? 0.0 : (sumWeighted / sumCredit);
    cout << fixed << setprecision(6) << gpa << '\n';
    return 0;
}
