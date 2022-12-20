#include <iostream>
#include <queue>
#include <vector>
#define NMAX 1001
using namespace std;
// 대동여지도

vector<vector<int>> map(NMAX);
vector<bool> visited(NMAX, false);
vector<int> memo(NMAX, -1);

void BFS(int start) {
    queue<pair<int, int>> q;
    visited[start] = true;
    memo[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int next : map[curr.second]) {
            if (!visited[next]) {
                visited[next] = true;
                memo[next] = curr.first + 1;
                q.push({curr.first + 1, next});
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, K, I, J, loc, hanyang = 0;
        long temp, H = 1000000000;
        cin >> N >> M >> K >> H;

        for (int i = 1; i < N; i++) {
            cin >> temp;
            if (H > temp) {
                H = temp;
                hanyang = i;
            }
        }
        for (int i = 0; i < M; i++) {
            cin >> I >> J;
            map[i].push_back(J);
            map[J].push_back(K);
        }
        BFS(hanyang);
        for (int i = 0; i < K; i++) {
            cin >> loc;
            cout << memo[loc] << endl;
        }
        vector<vector<int>>(NMAX).swap(map);
        vector<bool>(NMAX, false).swap(visited);
        vector<int>(NMAX, -1).swap(memo);
    }
    return 0;
}