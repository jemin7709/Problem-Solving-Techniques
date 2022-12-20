#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// 마법의 탑

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, P;
        cin >> n;
        set<pair<int, int>> tower;
        tower.insert({0, -1});
        for (int i = 1; i <= n; i++) {
            cin >> P;
            tower.insert({P, i});
            auto iter = tower.find({P, i});
            cout << (--iter)->second << ' ';
        }
        cout << endl;
    }
    return 0;
}