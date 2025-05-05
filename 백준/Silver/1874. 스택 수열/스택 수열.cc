#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std; 
int main() {
	
	stack <int> st; 
	int n; cin >> n; 
	vector <char> answer; 
	vector <int> input(n); 
	int number = 1; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a; 
		if (!st.empty() && st.top() == a) {
			st.pop(); 
			answer.push_back('-'); 
		}
		else if(number<=a) {

			while (number <= a) {
				st.push(number++);
				answer.push_back('+'); 
			}
			st.pop(); 
			answer.push_back('-'); 
		}
		else if (!st.empty() && st.top() > a) {
			cout << "NO"; 
			return 0; 

		}
		
	}
	for (auto x : answer) {
		cout << x << "\n"; 
	}
	return 0; 

}