#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int>> stick(4);

void print() {
    stack<int> temp = stick[2];
    if (temp.empty()) cout << 0 << endl;
    else {
        while (!temp.empty()) {
            cout << temp.top() << ' ';
            temp.pop();
        }
        cout << endl;
    }
}

void hanoi(int N, int &K, int from, int by, int to) {
    if (N == 1) {
        stick[to].push(stick[from].top());
        stick[from].pop();
        if (--K == 0) print();
    } else {
        hanoi(N - 1, K, from, to, by);
        stick[to].push(stick[from].top());
        stick[from].pop();
        if (--K == 0) print();
        hanoi(N - 1, K, by, from, to);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        for (int i = N; i > 0; i--) stick[1].push(i);
        hanoi(N, K, 1, 2, 3);
        vector<stack<int>>(4).swap(stick);
    }
    return 0;
}