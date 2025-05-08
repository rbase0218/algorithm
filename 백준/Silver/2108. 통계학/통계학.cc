#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <map>

using namespace std;

// N 개의 수들의 합을 N으로 나눈 값
int calculateAverage(vector<int> numbers) {
	double sum = 0;
	int size = numbers.size();
	for (int i = 0; i < size; ++i) {
		sum += numbers[i];
	}

	return round(sum / size);
}

// N개의 수를 오름차 순으로 나열했을 경우 중앙에 위치한 값
int findMedianValue(vector<int> numbers) {
    if (numbers.size() <= 1) return numbers[0];

	int halfSize = numbers.size() / 2;
	sort(numbers.begin(), numbers.end());
	return numbers[halfSize];
}

// 가장 많이 나타나는 값
int getModeValue(vector<int> numbers) {
    map<int, int> countMap;
    for (int num : numbers) {
        countMap[num]++;
    }

    int maxFreq = 0;
    for (const auto& pair : countMap) {
        maxFreq = max(maxFreq, pair.second);
    }

    vector<int> modes;
    for (const auto& pair : countMap) {
        if (pair.second == maxFreq) {
            modes.push_back(pair.first);
        }
    }

    if (modes.size() == 1) {
        return modes[0];
    }

    sort(modes.begin(), modes.end());
    return modes[1];
}

// 최댓값과 최솟값의 차이
int computeDataRange(vector<int> numbers) {
	if (numbers.size() <= 1) return 0;

	sort(numbers.begin(), numbers.end());
	return abs(numbers[0] - numbers[numbers.size() - 1]);
}

int main() {
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	cout << calculateAverage(num) << endl;
	cout << findMedianValue(num) << endl;
	cout << getModeValue(num) << endl;
	cout << computeDataRange(num) << endl;

	return 0;
}