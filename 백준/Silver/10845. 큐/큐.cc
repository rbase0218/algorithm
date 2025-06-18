#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int* queueArr = nullptr;
int capacity = 0;
int startIdx = 0;
int endIdx = 0;

void resize() {
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    int* newArr = new int[newCapacity];

    int currentSize = endIdx - startIdx;
    for (int i = 0; i < currentSize; i++) {
        newArr[i] = queueArr[startIdx + i];
    }

    delete[] queueArr;
    queueArr = newArr;
    capacity = newCapacity;
    startIdx = 0;
    endIdx = currentSize;
}

void push(int value)
{
    if (endIdx >= capacity) {
        resize();
    }
    queueArr[endIdx++] = value;
}

int pop()
{
    if (startIdx == endIdx) {
        return -1;
    }
    return queueArr[startIdx++];
}

int front()
{
    if (startIdx == endIdx) {
        return -1;
    }
    return queueArr[startIdx];
}

int back()
{
    if (startIdx == endIdx) {
        return -1;
    }
    return queueArr[endIdx - 1];
}

int size()
{
    return endIdx - startIdx;
}

int empty()
{
    return (startIdx == endIdx) ? 1 : 0;
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (command == "pop") {
            cout << pop() << "\n";
        }
        else if (command == "size") {
            cout << size() << "\n";
        }
        else if (command == "empty") {
            cout << empty() << "\n";
        }
        else if (command == "front") {
            cout << front() << "\n";
        }
        else if (command == "back") {
            cout << back() << "\n";
        }
    }

    delete[] queueArr;

    return 0;
}