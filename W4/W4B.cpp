#include <iostream>
#include <vector>

#define NMAX 100001
using namespace std;

vector<vector<int>> map(NMAX);
vector<bool> virus(NMAX, false);
vector<bool> visited(NMAX, false);
vector<int> ans;

int DFS(int start, int m) {
    int v = 0;
    visited[start] = true;
    for (int i: map[start]) {
        if (!visited[i]) {
            v += DFS(i, m);
        }
    }
    v += virus[start];
    if (v == m) ans.push_back(start);
    return v;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, u, v, l;
        cin >> n >> m;
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        for (int i = 0; i < m; i++) {
            cin >> l;
            virus[l] = true;
        }
        DFS(1, m);
        if (ans.size() == 1) cout << -1 << endl;
        else {
            if (ans[0] > ans[1]) cout << ans[1] << ' ' << ans[0] << endl;
            else cout << ans[0] << ' ' << ans[1] << endl;
        }
        vector<vector<int>>(NMAX).swap(map);
        vector<bool>(NMAX, false).swap(virus);
        vector<bool>(NMAX, false).swap(visited);
        vector<int>().swap(ans);
    }
    return 0;
}