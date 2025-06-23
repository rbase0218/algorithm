#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void selection_sort(vector<int>& numbers)
{
    int size = numbers.size();

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    selection_sort(num);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += num[i] * (n - i);
    }

    cout << sum;

    return 0;
}