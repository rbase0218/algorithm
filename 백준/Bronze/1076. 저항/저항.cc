#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	map<string, int> colors = {
		{"black", 0},
		{"brown", 1},
		{"red", 2},
		{"orange", 3},
		{"yellow", 4},
		{"green", 5},
		{"blue", 6},
		{"violet", 7},
		{"grey", 8},
		{"white", 9}
	};

	map<string, long long> colorCosts = {
		{"black", 1},
		{"brown", 10},
		{"red", 100},
		{"orange", 1000},
		{"yellow", 10000},
		{"green", 100000},
		{"blue", 1000000},
		{"violet", 10000000},
		{"grey", 100000000},
		{"white", 1000000000}
	};

	string color1, color2, color3;
	cin >> color1 >> color2 >> color3;
	
	long long resistance = (colors[color1] * 10 + colors[color2]) * colorCosts[color3];

	cout << resistance << endl;

	return 0;
}