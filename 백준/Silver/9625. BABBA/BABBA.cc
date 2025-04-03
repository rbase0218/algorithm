#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 : B		B : 1
// 2 : BA		B : 1, A : 1
// 3 : BAB		B : 2, A : 1
// 4 : BABBA	B : 3, A : 2
// 5 : BABBABAB B : 5, A : 3

int main(void) {
	int n;
	cin >> n;
	long long arr1[45];	// A
	long long arr2[45];	// B

	arr1[1] = 0;	// A
	arr2[1] = 1;	// B
	arr1[2] = 1;	// A
	arr2[2] = 1;	// B

	for (int i = 2; i <= n; ++i) 
	{
		arr1[i + 1] = arr1[i] + arr1[i - 1];
		arr2[i + 1] = arr2[i] + arr2[i - 1];
	}

	cout << arr1[n] << " " << arr2[n];

	return 0;
}