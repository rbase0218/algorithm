#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() 
{
	int a = -1, b = -1;

	while (a != 0 && b != 0)
	{
		cin >> a >> b;
		if (a != 0 && b != 0)
			cout << a + b << endl;
	}

	return 0;
}