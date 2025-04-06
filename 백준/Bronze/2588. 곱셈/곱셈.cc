#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num1, num2;
	cin >> num1 >> num2;

	cout << ((num2 % 100) % 10) * num1 << endl;
	cout << ((num2 % 100) / 10) * num1 << endl;
	cout << ((num2 / 100)) * num1 << endl;
	cout << num1 * num2 << endl;

	return 0;
}
