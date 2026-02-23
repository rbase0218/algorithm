#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (nums[i] > nums[j])
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

int main(void)
{
	int n, m, ans = 0;
	cin >> n >> m;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	bubble_sort(nums);

	int front = 0;
	int back = nums.size() - 1;
	while (front < back)
	{
		if (nums[front] + nums[back] == m)
		{
			ans++;

			front++;
			back--;
		}
		else if (nums[front] + nums[back] > m)
			back--;
		else
			front++;
	}

	cout << ans;

	return 0;
}