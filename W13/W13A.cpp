#include <algorithm>
#include <iostream>
#include <vector>
#define NMAX 1001
using namespace std;
// 맷돼지

vector<vector<pair<int, int>>> graph(NMAX);
vector<bool> visited(NMAX, false);

void DFS(int start) {
    visited[start] = true;
    cout << start << endl;
    for (auto next : graph[start]) {
        if (visited[next.second] == false) {
            DFS(next.second);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, H, l1, l2;
        cin >> N >> M;
        vector<pair<int, int>> height(N);

        for (int i = 0; i < N; i++) {
            cin >> H;
            height[i] = {H, i};
        }
        for (int i = 0; i < M; i++) {
            cin >> l1 >> l2;
            graph[l1].push_back({height[l2].first, l2});
            graph[l2].push_back({height[l1].first, l1});
        }
        for (int i = 0; i < N; i++) sort(graph[i].begin(), graph[i].end());
        sort(height.begin(), height.end());
        for (auto location : height) {
            if (visited[location.second] == false) {
                DFS(location.second);
            }
        }
        vector<vector<pair<int, int>>>(NMAX).swap(graph);
        vector<bool>(NMAX, false).swap(visited);
    }
    return 0;
}