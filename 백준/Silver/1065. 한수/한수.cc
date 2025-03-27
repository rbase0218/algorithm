#include <iostream>
using namespace std;

int main(void) {
	int num = 0, answer = 99;
	cin >> num;

	if (num < 100)
		cout << num << endl;
	else
	{
		int hun, ten, one;
		for (int i = 100; i <= num; ++i) 
		{
			hun = i / 100;
			ten = (i % 100) / 10;
			one = (i % 100) % 10;

			if ((hun - ten) == (ten - one))
			{
				answer++;
			}
		}
		cout << answer << endl;
	}

	return 0;
}