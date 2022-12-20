#include <iostream>
#include <stack>
#include <vector>

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
    int temp;
    if (N == 1) {
        temp = stick[from].top();
        while (!stick[from].empty() && stick[from].top() == temp) {
            stick[to].push(stick[from].top());
            stick[from].pop();
            if (--K == 0) print();
        }
    } else {
        hanoi(N - 1, K, from, to, by);
        temp = stick[from].top();
        while (!stick[from].empty() && stick[from].top() == temp) {
            stick[to].push(stick[from].top());
            stick[from].pop();
            if (--K == 0) print();
        }
        hanoi(N - 1, K, by, from, to);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K, in;
        stack<int> temp;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> in;
            temp.push(in);
        }
        cin >> K;
        for (int i = N; i > 0; i--) {
            for (int j = 0; j < temp.top(); j++) stick[1].push(i);
            temp.pop();
        }
        hanoi(N, K, 1, 2, 3);

    }
    return 0;
}