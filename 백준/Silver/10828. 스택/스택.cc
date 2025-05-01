#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class stack {
private:
	vector<int> data;
public:
	
	void push(int x) {
		data.push_back(x);
	}

	int top()
	{
		if (empty())
			return -1;
		return data[data.size() - 1];
	}

	int size() {
		return data.size();
	}

	int empty() {
		return data.size() == 0 ? 1 : 0;
	}

	int pop() {
		if (empty())
			return -1;
		else
		{
			int n = data[size() - 1];
			data.erase(data.end() - 1);
			return n;
		}
	}
};

int main() {
	int tc;
	stack* buffer = new stack();
	cin >> tc;

	string command;
	int n;
	while (tc--) {
		cin >> command;

		if (command == "push")
		{
			cin >> n;
			buffer->push(n);
		}
		else if (command == "pop")
		{
			cout << buffer->pop() << endl;
		}
		else if (command == "top")
		{
			cout << buffer->top() << endl;
		}
		else if (command == "size")
		{
			cout << buffer->size() << endl;
		}
		else if (command == "empty")
		{
			cout << buffer->empty() << endl;
		}
	}
	
	return 0;
}