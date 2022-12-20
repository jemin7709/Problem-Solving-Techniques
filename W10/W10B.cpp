#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 상어 아쿠아리움

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<pair<int, int>> s;
        vector<int> a;
        priority_queue<int, vector<int>, greater<int>> q;

        for (int i = 0; i < N; i++) cin >> s[i].first >> s[i].second;
        for (int i = 0; i < N; i++) cin >> a[i];

        sort(s.begin(), s.end());
        sort(a.begin(), a.end());

        int index = 0, count = 0;
        for (int i = 0; i < M; i++) {
            while (index < N && s[index].first <= a[i]) {
                q.push(s[index].second);
                index++;
            }
            while (!q.empty() && q.top() < a[i]) q.pop();
            if (!q.empty()) {
                q.pop();
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}