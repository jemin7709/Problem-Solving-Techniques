#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int length = 0;
        stack<int> stack;
        stack.push(0);
        string S;
        cin >> S;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'C') {
                stack.push(i + 1);
            } else {
                stack.pop();
                if (stack.empty()) stack.push(i + 1);
                else {
                    length = max(length, (i + 1) - stack.top());
                }
            }
        }
        cout << length << endl;
    }
    return 0;
}