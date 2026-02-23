#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    string text;
    cin >> text;

    int zero = 0, one = 0;
    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] == '0') zero++;
        else one++;
    }
    
    zero /= 2;
    one /= 2;

    string newText = "";
    for (int i = 0; i < zero + one; ++i)
    {
        if (i < zero) newText += '0';
        else newText += '1';
    }

    cout << newText;

    return 0;
}