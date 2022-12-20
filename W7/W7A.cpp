#include <iostream>
#include <stack>
#include <string>
using namespace std;
// 후위수식 계산

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        stack<int> stack;
        string input;
        cin >> input;

        for (char c : input) {
            if (c != '+' && c != '-' && c != '*') stack.push(c - '0');
            else {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                if (c == '+') stack.push(b + a);
                if (c == '-') stack.push(b - a);
                if (c == '*') stack.push(b * a);
            }
        }
        cout << stack.top() << endl;
    }
    return 0;
}