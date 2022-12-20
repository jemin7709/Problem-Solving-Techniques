#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#define NMAX 50001
using namespace std;

vector<vector<pair<int, int>>> map(NMAX);
vector<int> memo(NMAX, 0);

int DFS(int start) {
    int &len = memo[start];
    if (len != 0) return len;
    for (pair<int, int> i: map[start]) {
        len = max(len, DFS(i.first) + i.second);
    }
    return len;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, y, t, i1, i2, max_len = 0;
        string s1, s2;
        cin >> N >> M;

        unordered_map<int, string> index_location;
        unordered_map<string, int> location_index;
        unordered_map<int, int> index_year;

        for (int i = 0; i < N; i++) {
            cin >> s1 >> y;
            location_index[s1] = i;
            index_year[i] = y;
        }
        for (int i = 0; i < M; i++) {
            cin >> s1 >> s2 >> t;
            i1 = location_index[s1];
            i2 = location_index[s2];
            if (index_year[i1] > index_year[i2]) map[i2].push_back({i1, t});
            else map[i1].push_back({i2, t});
        }
        for (int i = 0; i < N; i++) {
            max_len = max(DFS(i), max_len);
        }
        cout << max_len << endl;
        vector<vector<pair<int, int>>>(NMAX).swap(map);
        vector<int>(NMAX, 0).swap(memo);
    }
    return 0;
}