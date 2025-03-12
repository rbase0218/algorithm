#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string command;
    cin >> command;

    list<char> text;
    for (char c : command) {
        text.push_back(c);
    }

    auto cursor_point = text.end();

    int command_count;
    cin >> command_count;

    for (int i = 0; i < command_count; ++i) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cursor_point != text.begin()) {
                cursor_point--;
            }
        }
        else if (cmd == 'D') {
            if (cursor_point != text.end()) {
                cursor_point++;
            }
        }
        else if (cmd == 'B') {
            if (cursor_point != text.begin()) {
                cursor_point = text.erase(--cursor_point);
            }
        }
        else if (cmd == 'P') {
            char input_text;
            cin >> input_text;
            text.insert(cursor_point, input_text);
        }
    }

    for (char c : text) {
        cout << c;
    }
    return 0;
}