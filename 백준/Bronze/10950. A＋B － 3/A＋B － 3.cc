#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    
    while (n > 0)
    {
        cin >> a >> b;
        cout << a + b << endl;
        n--;
    }

    return 0;
}