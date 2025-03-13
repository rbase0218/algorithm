#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int tc = 0;
    cin >> tc;

    for (int t = 0; t < tc; ++t) {
        string command;
        cin >> command;

        int arr_size = 0;
        cin >> arr_size;

        string arr_str;
        cin >> arr_str;

        vector<int> arr;
        string num_str = "";

        for (int i = 1; i < arr_str.size() - 1; ++i) {
            if (arr_str[i] == ',') {
                if (!num_str.empty()) {
                    arr.push_back(stoi(num_str));
                    num_str = "";
                }
            }
            else if (arr_str[i] >= '0' && arr_str[i] <= '9') {
                num_str += arr_str[i];
            }
        }

        if (!num_str.empty()) {
            arr.push_back(stoi(num_str));
        }

        int start_idx = 0;
        int end_idx = arr.size() - 1;
        bool is_reverse = false;
        bool has_error = false;

        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'R') {
                is_reverse = !is_reverse;
            }
            else if (command[i] == 'D') {
                if (start_idx > end_idx) {
                    has_error = true;
                    break;
                }

                if (is_reverse) {
                    --end_idx;
                }
                else {
                    ++start_idx;
                }
            }
        }

        if (has_error) {
            cout << "error" << endl;
        }
        else {
            cout << "[";
            if (!is_reverse) {
                for (int i = start_idx; i <= end_idx; ++i) {
                    cout << arr[i];
                    if (i != end_idx) {
                        cout << ",";
                    }
                }
            }
            else {
                for (int i = end_idx; i >= start_idx; --i) {
                    cout << arr[i];
                    if (i != start_idx) {
                        cout << ",";
                    }
                }
            }
            cout << "]" << endl;
        }

        arr.clear();
        start_idx = 0;
        end_idx = 0;
        is_reverse = false;
    }
    return 0;
}