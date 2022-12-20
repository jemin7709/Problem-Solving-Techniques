#include <iostream>
#include <vector>
#define NMAX 251
#define INF 10000000001
using namespace std;
// 대동여지도 2

vector<vector<int>> cost(NMAX, vector<int>(NMAX, INF));

void fw() {
    for (int me = 0; me < NMAX; me++) {
        for (int caller = 0; caller < NMAX; caller++) {
            for (int callee = 0; callee < NMAX; callee++) {
                cost[caller][callee] = min(cost[caller][callee],
                                           cost[caller][me] + cost[me][callee]);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, Q, u, v, w;
        cin >> N >> M >> Q;
        for (int i = 0; i < M; i++) {
            cin >> u >> v >> w;
            cost[u][v] = w;
            cost[v][u] = w;
        }
        fw();
        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            cout << cost[u][v] << endl;
        }
        vector<vector<int>>(NMAX, vector<int>(NMAX, INF)).swap(cost);
    }
    return 0;
}