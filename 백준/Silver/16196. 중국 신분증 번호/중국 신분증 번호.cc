#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool IsLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int GetLastDay(int year, int month) {
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && IsLeapYear(year)) return 29;
	return days[month];
}

int main(void)
{
    string code;
    int n;

    if (!(cin >> code >> n)) return 0;

    vector<string> regions(n);
    bool region_ok = false;
    for (int i = 0; i < n; ++i) {
        cin >> regions[i];
        if (code.substr(0, 6) == regions[i]) {
            region_ok = true;
        }
    }

    // 1. 지역 코드 검증
    if (!region_ok) {
        cout << "I";
        return 0;
    }

    // 2. 생일 코드 검증
    int year = stoi(code.substr(6, 4));
    int month = stoi(code.substr(10, 2));
    int day = stoi(code.substr(12, 2));

    if (year < 1900 || year > 2011 || month < 1 || month > 12 || day < 1 || day > GetLastDay(year, month)) {
        cout << "I";
        return 0;
    }

    // 3. 순서 코드 검증
    if (code.substr(14, 3) == "000") {
        cout << "I";
        return 0;
    }

    // 4. 체크섬 코드 검증
    int sum = 0;
    for (int i = 0; i < 17; ++i) {
        int weight = (1LL << (18 - (i + 1)));
        sum += (int)(code[i] - '0') * weight;
    }

    int check = (code[17] == 'X') ? 10 : (code[17] - '0');

    if ((sum + check) % 11 != 1) {
        cout << "I";
        return 0;
    }

    if ((code[16] - '0') % 2 != 0) 
        cout << "M";
    else 
        cout << "F";

	return 0;
}