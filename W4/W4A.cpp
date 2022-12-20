#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K, W, V, ans = 0;
        cin >> N >> K;

        vector<int> Ws;
        vector<int> Vs;
        multimap<int, int, greater<int>> VW_index;
        for (int i = 0; i < N; i++) {
            cin >> W;
            Ws.push_back(W);
        }
        for (int i = 0; i < N; i++) {
            cin >> V;
            Vs.push_back(V);
            VW_index.insert({V / Ws[i], i});
        }
        for (auto iter = VW_index.begin(); iter != VW_index.end(); iter++) {
            if (K >= Ws[iter->second]) {
                ans += Vs[iter->second];
                K -= Ws[iter->second];
            } else {
                ans += K * iter->first;
                K = 0;
            }
            if (K == 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}