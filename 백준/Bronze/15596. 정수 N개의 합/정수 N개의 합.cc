#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int>& a) {
    long long answer = 0;
    for (int i = 0; i < a.size(); ++i) {
        answer += a[i];
    }
    return answer;
}
