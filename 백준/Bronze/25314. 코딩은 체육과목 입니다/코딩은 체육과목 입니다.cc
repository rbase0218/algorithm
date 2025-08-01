#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i += 4)
		cout << "long ";
	cout << "int";

	return 0;
}