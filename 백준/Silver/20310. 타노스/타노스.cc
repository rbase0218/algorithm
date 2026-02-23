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

    zero *= 0.5;
    one *= 0.5;
    
    for (int i = 0; i < text.size(); ++i) {
        if (zero != 0 && text[text.size() - (i + 1)] == '0')
        {
            text[text.size() - (i + 1)] = '9';
            zero--;
        }
        if (one != 0 && text[i] == '1')
        {
            text[i] = '9';
            one--;
        }
    }

    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] != '9')
        {
            cout << text[i];
        }
    }

    return 0;
}